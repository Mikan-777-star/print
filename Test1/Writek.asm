bits 64

section .text

global Writek

Writek:
    mov rax, 1
    syscall
    mov rax, 0
    ret