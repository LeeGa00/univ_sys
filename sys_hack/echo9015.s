section .text
	global_echoStart

_echoStart:
	;xor rax, rax ; same meaning with mov rax, 0
	mov rax, 0
	mov rdi, 0
	mov rsi, msg
	mov rdx, 20
	syscall 

	;mov msg, rax
	mov rax, 1
	mov rdi, 1
	syscall

	mov rax, 60
	mov rdi, 0 
	syscall 	
