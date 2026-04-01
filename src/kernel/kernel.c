#include "vga.h"
#include "idt.h"
#include "keyboard.h"
#include "shell.h"

void kernel_main(void) {
    vga_init();
    vga_clear();
    vga_println("HimayOS v0.1");
    vga_println("Booting...");
    
    idt_init();
    vga_println("Interrupts initialized");
    
    keyboard_init();
    vga_println("Keyboard initialized");
    
    vga_println("");
    vga_println("Starting shell...");
    vga_println("");
    
    shell_run();
}
