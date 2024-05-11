    .data
nome: .space 50      
msg: .asciiz "Por favor, informe seu nome: "
saudacao: .asciiz "Olá Sr(a). "

    .text
    .globl main

main:
    li $v0, 4           
    la $a0, msg         
    syscall

    li $v0, 8           
    la $a0, nome        
    li $a1, 50         
    syscall

    li $v0, 4          
    la $a0, saudacao    
    syscall

    move $a0, $v0       
    li $v0, 4           
    syscall


