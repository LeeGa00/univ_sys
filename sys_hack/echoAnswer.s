section .text
	global_start

_start:
	xor rax, rax
	mov rbx, rax
	mov rcx, rax
	mov rdx, rax

	sub rsp, 63
	mov rdi, 0
	mov rsi, rsp
	mov rdx, 63
	syscall

	mov rax, 1
	mov rdi, 1
	mov rsi, rsp
	mov rdx, 63
	syscall

	mov rax, 60
	syscall
