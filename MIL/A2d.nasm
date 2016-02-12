;	Problem Statement:
;	Write x86/64 bit ALP to perform non-overlapped and overlapped block transfer (with string-specific or without spring-specific instructions).
;	Block containing data can be defined in the data segment.

global _start

section .data		;constant data and messages
welcome db 0xA,"This program illustrates non-overlapped block transfer with string specific instruction.",0xA
lwelcome equ $-welcome
request db 0xA,"Enter offset to transfer it: "
lrequest equ $-request
blk1 db "MCOE Pune.",0xA
lblk equ $-blk1

section .bss
	;macros
%macro print 2
mov rax, 0x1
mov rdi, 0x1
mov rsi, %1
mov rdx, %2
syscall
%endmacro

	;variables
blk2 times 2 resb lblk
off resb 2

section .text		;code
_start:

mov rcx, lblk
mov rsi, blk1
mov rdi, blk2

transfer1:			;non-overlapped transfer
mov al, byte[esi]
mov byte[edi], al
inc rsi
inc rdi
loop transfer1

print request, lrequest
mov rax, 0
mov rdi, 0
mov rsi, off
mov rdx, 2
syscall

xor rdx, rdx
mov dl, byte[off]


cmp dl, 0x39
jle norm
sub dl, 0x07
norm:
sub dl, 0x30
push rdx

lea rax, [blk2+lblk-1]
mov rcx, lblk
mov rsi, rax
add rax, rdx
mov rdi, rax

transfer2:			;overlapped transfer
mov al, byte[esi]
mov byte[edi], al
dec rsi
dec rdi
loop transfer2

print welcome, lwelcome

print blk2, lblk+lblk

mov rax, 0x3c
mov rdi, 0x0
syscall
