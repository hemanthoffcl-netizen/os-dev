#include "shell.h"
#include "vga.h"
#include "keyboard.h"

#define MAX_CMD_LEN 256

static char cmd_buffer[MAX_CMD_LEN];
static int cmd_pos = 0;

static void shell_print_prompt(void) {
    vga_print("himay@os> ");
}

static void shell_process_command(const char* cmd) {
    if (cmd[0] == '\0') {
        return;
    }
    
    if (cmd[0] == 'c' && cmd[1] == 'l' && cmd[2] == 'e' && cmd[3] == 'a' && cmd[4] == 'r') {
        vga_clear();
        return;
    }
    
    if (cmd[0] == 'h' && cmd[1] == 'e' && cmd[2] == 'l' && cmd[3] == 'p') {
        vga_println("Available commands:");
        vga_println("  clear  - Clear the screen");
        vga_println("  help   - Show this help message");
        vga_println("  echo   - Print text");
        vga_println("  ver    - Show OS version");
        vga_println("  reboot - Reboot (not implemented)");
        return;
    }
    
    if (cmd[0] == 'e' && cmd[1] == 'c' && cmd[2] == 'h' && cmd[3] == 'o') {
        const char* arg = cmd + 5;
        while (*arg == ' ') arg++;
        vga_println(arg);
        return;
    }
    
    if (cmd[0] == 'v' && cmd[1] == 'e' && cmd[2] == 'r') {
        vga_println("HimayOS v0.1 - Hobby Operating System");
        return;
    }
    
    vga_print("Unknown command: ");
    vga_println(cmd);
    vga_println("Type 'help' for available commands");
}

static void shell_handle_input(char c) {
    if (c == '\n' || c == '\r') {
        vga_putchar('\n');
        cmd_buffer[cmd_pos] = '\0';
        shell_process_command(cmd_buffer);
        cmd_pos = 0;
        shell_print_prompt();
        return;
    }
    
    if (c == '\b') {
        if (cmd_pos > 0) {
            cmd_pos--;
            vga_putchar('\b');
        }
        return;
    }
    
    if (c >= 32 && c < 127) {
        if (cmd_pos < MAX_CMD_LEN - 1) {
            cmd_buffer[cmd_pos++] = c;
            vga_putchar(c);
        }
    }
}

void shell_init(void) {
    cmd_pos = 0;
}

void shell_run(void) {
    shell_init();
    shell_print_prompt();
    
    while (1) {
        if (keyboard_has_input()) {
            char c = keyboard_read_char();
            shell_handle_input(c);
        }
    }
}
