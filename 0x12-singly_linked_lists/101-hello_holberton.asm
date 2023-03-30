section .data
    hello db 'Hello, Holberton', 10, 0 ; 10 is the newline character, 0 is the null terminator

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    lea rdi, [hello] ; Load the address of the hello string into rdi
    xor eax, eax ; Clear eax to indicate there are no floating-point arguments
    call printf ; Call printf with the hello string as the argument

    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret

