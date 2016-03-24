;	Problem Statement:
;	Write x86/64 bit ALP to perform non-overlapped and overlapped block transfer (with string-specific or without spring-specific instructions).
;	Block containing data can be defined in the data segment.

global _start

section .data		;constant data and messages
welcome db 10,"This program illustrates non-overlapped block transfer with string specific instruction.",10
lwelcome equ $-welcome
blk1 db 10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,7,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,7,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,7,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,7,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,7,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,7,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,7,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10,"Hello, I am a student from P.E.S.'s Modern College of Engineering. ",10
lblk equ $-blk1

section .bss
	;macros
%macro print 2
mov eax, 4
mov ebx, 1
mov ecx, %1
mov edx, %2
int 0x80
%endmacro

	;variables
blk2 resb lblk

section .text		;code
_start:

mov cx, lblk
mov esi, blk1
mov edi, blk2

transfer:
mov al, byte[esi]
mov byte[edi], al
inc esi
inc edi
loop transfer

print welcome, lwelcome

print blk2, lblk

mov eax, 1
mov edi, 0
int 0x80
