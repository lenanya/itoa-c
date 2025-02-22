.global write
.global _exit

write:
	mov $1, %rax
	syscall
	ret

_exit:
	mov $60, %rax
	syscall
