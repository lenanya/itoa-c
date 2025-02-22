.global write
.global _exit

write:
    movq $1, %rax
    syscall
    ret

_exit:
    movq $60, %rax 
    syscall

