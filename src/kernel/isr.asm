[bits 32]

global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

extern isr_handler

isr0:
    push byte 0
    push byte 0
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr1:
    push byte 0
    push byte 1
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr2:
    push byte 0
    push byte 2
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr3:
    push byte 0
    push byte 3
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr4:
    push byte 0
    push byte 4
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr5:
    push byte 0
    push byte 5
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr6:
    push byte 0
    push byte 6
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr7:
    push byte 0
    push byte 7
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr8:
    push byte 8
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 4
    iret

isr9:
    push byte 9
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 4
    iret

isr10:
    push byte 10
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 4
    iret

isr11:
    push byte 11
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 4
    iret

isr12:
    push byte 12
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 4
    iret

isr13:
    push byte 13
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 4
    iret

isr14:
    push byte 14
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 4
    iret

isr15:
    push byte 15
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 4
    iret

isr16:
    push byte 0
    push byte 16
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr17:
    push byte 0
    push byte 17
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr18:
    push byte 0
    push byte 18
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr19:
    push byte 0
    push byte 19
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr20:
    push byte 0
    push byte 20
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr21:
    push byte 0
    push byte 21
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr22:
    push byte 0
    push byte 22
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr23:
    push byte 0
    push byte 23
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr24:
    push byte 0
    push byte 24
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr25:
    push byte 0
    push byte 25
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr26:
    push byte 0
    push byte 26
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr27:
    push byte 0
    push byte 27
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr28:
    push byte 0
    push byte 28
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr29:
    push byte 0
    push byte 29
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr30:
    push byte 0
    push byte 30
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret

isr31:
    push byte 0
    push byte 31
    pushad
    push ds
    push es
    push fs
    push gs
    push esp
    call isr_handler
    add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    popad
    add esp, 8
    iret
