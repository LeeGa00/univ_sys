section .data ; data section 
	msg db "hello ASM" ; save the string "Hello ASM" into the msg

section .text ; text section
	global_start ; start function in .text

_start:
	mov rax, 1 ; save 1 to rax, meaning that we are going to use sys_write
	mov rdi, 1 ; save 1 to rdi, meaning that we are going to use stdout (1), whick is the screen
	mov rsi, msg ; save msg to rsi, meaning that the string start address will be saved into rsi
	mov rdx, 12 ; save 12 to rdx, meaning that the size of the string to be ritten (into stdout)
	syscall ; call the system call, sys_write

	mov rax, 60 ; save 60 to rax, meaning that we are going to use sys_exit
	mov rdi, 0 ; save to rdi, meaning that the program exits without errors
	syscall ; call the system call, sys_exit
