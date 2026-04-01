#include "vga.h"
#include <stdint.h>
#include <string.h>

static uint16_t* vga_buffer = (uint16_t*) 0xB8000;
static uint8_t vga_color = 0;
static int vga_cursor_x = 0;
static int vga_cursor_y = 0;

void vga_init(void) {
    vga_set_color(VGA_LIGHT_GREY, VGA_BLACK);
}

void vga_clear(void) {
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vga_buffer[i] = (vga_color << 8) | ' ';
    }
    vga_cursor_x = 0;
    vga_cursor_y = 0;
    vga_cursor_move(0, 0);
}

void vga_set_color(uint8_t fg, uint8_t bg) {
    vga_color = (bg << 4) | fg;
}

void vga_putchar(char c) {
    if (c == '\n') {
        vga_cursor_x = 0;
        vga_cursor_y++;
    } else if (c == '\r') {
        vga_cursor_x = 0;
    } else if (c == '\t') {
        vga_cursor_x = (vga_cursor_x + 8) & ~7;
    } else if (c == '\b') {
        if (vga_cursor_x > 0) {
            vga_cursor_x--;
            vga_buffer[vga_cursor_y * VGA_WIDTH + vga_cursor_x] = (vga_color << 8) | ' ';
        }
    } else if (c >= 32 && c < 127) {
        vga_buffer[vga_cursor_y * VGA_WIDTH + vga_cursor_x] = (vga_color << 8) | c;
        vga_cursor_x++;
    }
    
    if (vga_cursor_x >= VGA_WIDTH) {
        vga_cursor_x = 0;
        vga_cursor_y++;
    }
    
    if (vga_cursor_y >= VGA_HEIGHT) {
        for (int i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++) {
            vga_buffer[i] = vga_buffer[i + VGA_WIDTH];
        }
        for (int i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_HEIGHT * VGA_WIDTH; i++) {
            vga_buffer[i] = (vga_color << 8) | ' ';
        }
        vga_cursor_y = VGA_HEIGHT - 1;
    }
    
    vga_cursor_move(vga_cursor_x, vga_cursor_y);
}

void vga_print(const char* str) {
    while (*str) {
        vga_putchar(*str);
        str++;
    }
}

void vga_println(const char* str) {
    vga_print(str);
    vga_putchar('\n');
}

void vga_cursor_move(int x, int y) {
    uint16_t pos = y * VGA_WIDTH + x;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}
