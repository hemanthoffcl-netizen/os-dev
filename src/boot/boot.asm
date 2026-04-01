[bits 32]
[extern kernel_main]

global start
global _stack_top

section .text
start:
    mov esp, _stack_top
    call kernel_main
    cli
    hlt

section .bss
align 16
_stack_bottom:
    resb 8192
_stack_top:
