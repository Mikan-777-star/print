bits 64

section .text

global Writek


;Writek関数本体
;mov rax,1でWriteのシステムコールをしていして
;SystemCallで実行

Writek:
    mov rax, 1
    syscall
    ret