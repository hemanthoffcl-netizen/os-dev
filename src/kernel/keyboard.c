#include "keyboard.h"
#include "vga.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define KEYBOARD_BUFFER_SIZE 256

static char keyboard_buffer[KEYBOARD_BUFFER_SIZE];
static int buffer_start = 0;
static int buffer_end = 0;

static const char scancode_to_ascii[] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

static void keyboard_buffer_push(char c) {
    keyboard_buffer[buffer_end] = c;
    buffer_end = (buffer_end + 1) % KEYBOARD_BUFFER_SIZE;
}

static char keyboard_buffer_pop(void) {
    char c = keyboard_buffer[buffer_start];
    buffer_start = (buffer_start + 1) % KEYBOARD_BUFFER_SIZE;
    return c;
}

static int keyboard_buffer_empty(void) {
    return buffer_start == buffer_end;
}

void keyboard_handler(void) {
    uint8_t status;
    uint8_t keycode;
    
    __asm__ volatile("inb %1, %0" : "=a"(status) : "Nd"(KEYBOARD_STATUS_PORT));
    
    if (status & 0x01) {
        __asm__ volatile("inb %1, %0" : "=a"(keycode) : "Nd"(KEYBOARD_DATA_PORT));
        
        if (keycode < 0x80) {
            if (keycode < sizeof(scancode_to_ascii) && scancode_to_ascii[keycode]) {
                keyboard_buffer_push(scancode_to_ascii[keycode]);
            }
        }
    }
}

void keyboard_init(void) {
    buffer_start = 0;
    buffer_end = 0;
}

char keyboard_read_char(void) {
    while (keyboard_buffer_empty()) {
        __asm__ volatile("hlt");
    }
    return keyboard_buffer_pop();
}

int keyboard_has_input(void) {
    return !keyboard_buffer_empty();
}
