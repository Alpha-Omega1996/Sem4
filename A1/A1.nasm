global _start

section .data
welcome db 0xA,"This program will allow you to enter and add 32/64 bit Hexadecimal numbers.",0xA,0xA
lwelcome equ $-welcome
promptC db 0xA,"Enter the count of numbers you want to add: "
lpromptC equ $-promptC
promptN db 0xA,"Enter number: "
lpromptN equ $-promptN
response db 0xA,"The Sum is: "
lresponse equ $-response
promptE db 0xA,0xA,"You have not followed the instructions correctly, please try again!"
lpromptE equ $-promptE
size equ 17

section .bss
		;macros
%macro print 2
mov rdx, %2
mov rsi, %1
mov rdi, 1
mov rax, 1
syscall
%endmacro

%macro scan 2
mov rdx, %2
mov rsi, %1
mov rdi, 0
mov rax, 0
syscall
%endmacro

		;variables
mem_start resq 1	;start address of dynamically allocated memory
mem_end resq 1		;end address of dynamically allocated memory
buffer resb size	;a 16 digit number + '\n'				ASCII
sum resq 1		;reserving 1 64-bit space for sum result		actual value
count resb 2		;2 bytes can store a value (used as counter) of 255	actual value

		;size of variables = 15*8 + 17 + 1*8 + 2 = 147 bytes

section .text

print welcome, lwelcome
print promptC, lpromptC
scan buffer, size


xor rax, rax
xor rdx, rdx
mov rcx, rdx
mov ax, word[buffer]	;takes 2 digits
mov dx, ax

cmp dl, 0x39
jle normL
sub dl, 0x27		;using small characters
normL:
sub 0x30
cmp dh, 0x39
jle normH
sub dh, 0x27		;using small characters
normH:
sub dh, 0x30
xor ax, ax
mov al, dh
mul al, 4
mov dh, 0
add dx, ax
mov word[count], dx

xor rax, rax
mov rax, 0x0C
mov rdi, [mem_start]
syscall

mov mem_start, rax
xor rax, rax
mov rbx, [count]
lea rax, [mem_start+rbx*16]
mov rdi, rax
mov rax, 0x0C
syscall

mov mem_end, rax

