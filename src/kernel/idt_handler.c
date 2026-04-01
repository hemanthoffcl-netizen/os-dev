#include "idt.h"
#include "vga.h"

extern void pic_send_eoi(uint8_t irq);
extern void keyboard_handler(void);

const char* exception_messages[] = {
    "Division By Zero", "Debug", "Non Maskable Interrupt", "Breakpoint",
    "Overflow", "Bound Range Exceeded", "Invalid Opcode", "Device Not Available",
    "Double Fault", "Coprocessor Segment Overrun", "Bad TSS", "Segment Not Present",
    "Stack Fault", "General Protection Fault", "Page Fault", "Reserved",
    "x87 FPU Error", "Alignment Check", "Machine Check", "SIMD FPU Exception",
    "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved",
    "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Security Exception", "Reserved"
};

void isr_handler(struct cpu_regs* regs) {
    vga_print("\nCPU Exception: ");
    if (regs->int_no < 32) {
        vga_print(exception_messages[regs->int_no]);
    }
    while (1) { __asm__ volatile("hlt"); }
}

void irq_handler(struct cpu_regs* regs) {
    if (regs->int_no == 33) {
        keyboard_handler();
    }
    pic_send_eoi((uint8_t)(regs->int_no - 32));
}
