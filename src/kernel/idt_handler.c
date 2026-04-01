#include "idt.h"
#include "vga.h"

extern void pic_send_eoi(uint8_t irq);

const char* exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Overflow",
    "Bound Range Exceeded",
    "Invalid Opcode",
    "Device Not Available",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Reserved",
    "x87 FPU Error",
    "Alignment Check",
    "Machine Check",
    "SIMD FPU Exception",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Security Exception",
    "Reserved"
};

void isr_handler(struct cpu_regs* regs) {
    vga_print("\nCPU Exception: ");
    if (regs->int_no < 32) {
        vga_print(exception_messages[regs->int_no]);
    } else {
        vga_print("Unknown Exception ");
    }
    vga_print(" (");
    
    char buf[12];
    int i = 0;
    uint32_t n = regs->int_no;
    if (n == 0) {
        buf[i++] = '0';
    } else {
        while (n > 0) {
            buf[i++] = "0123456789"[n % 10];
            n /= 10;
        }
    }
    buf[i] = '\0';
    
    for (int j = 0; j < i / 2; j++) {
        char tmp = buf[j];
        buf[j] = buf[i - j - 1];
        buf[i - j - 1] = tmp;
    }
    
    vga_print(buf);
    vga_println(")");
    
    while (1) {
        __asm__ volatile("hlt");
    }
}

void irq_handler(struct cpu_regs* regs) {
    pic_send_eoi((uint8_t)(regs->int_no - 32));
    
    if (regs->int_no == 33) {
    }
}
