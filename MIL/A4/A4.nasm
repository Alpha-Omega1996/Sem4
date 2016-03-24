global _start

section .data

welcome db 0xA,0xA,"This program will take a string/sentence from you and check whether it is a palindrome or not.",0xA
lwelcome equ $-welcome
menu db 0xA,"Operations performable: ",0xA
     db 0x9,"1) Enter a string.",0xA
     db 0x9,"2) Calculate length of string.",0xA
     db 0x9,"3) Show the reverse of string.",0xA
     db 0x9,"4) Check if string is palindrome.",0xA
     db 0x9,"5) Exit",0xA,
     db 0xA,"Enter choice: "
lmenu equ $-menu
prompt db 0xA,"Enter any string/sentence: "
lprompt equ $-prompt
response1 db 0xA,"The length of entered String is "
lresponse1 equ $-response1
response2 db 0xA,"The reverse of entered String is "
lresponse2 equ $-response2
option1 db 0xA,"The entered String is a palindrome."
loption1 equ $-option1
option2 db 0xA,"The entered String is not a palindrome."
loption2 equ $-option2

section .bss
	;macros
%macro print 2
mov rax, 1
mov rdi, 1
mov rsi, %1
mov rdx, %2
syscall
%endmacro

%macro scan 2
mov rax, 0
mov rdi, 0
mov rsi, %1
mov rdx, %2
syscall
%endmacro

	;variables
buffer resb 30
len resb 2
plen resb 2
choice resb 2
string resb 30
revstr resb 30
erase db 30
	;size of variables = 30B + 2B + 2B + 2B + 30B + 30B + 30B = 126B

section .text
_start:
	print welcome, lwelcome

	repeat:

		print menu, lmenu
		scan choice, 2
		cmp byte[choice], '1'
		je choice1
		cmp byte[choice], '2'
		je choice2
		cmp byte[choice], '3'
		je choice3
		cmp byte[choice], '4'
		je choice4
		cmp byte[choice], '5'
		je exit

	choice1:
			;input the string
		xor rcx, rcx
		mov rcx, 30
		mov rsi, erase
		mov rdi, buffer
		rep movsb
		mov rcx, 30
		mov rdi, string
		rep movsb
		mov rcx, 30
		mov rdi, revstr
		rep movsb
		mov rcx, 2
		mov rdi, len
		rep movsb

		print prompt, lprompt
		scan buffer, 30
		dec rax
		push rax
		jmp repeat

	choice2:
			;store length of string
		print response1, lresponse1
		pop rax
		push rax

		xor rbx, rbx
		mov rbx, rax
		and rbx, 0x0F0
		rol rbx, 4
		and rax, 0x0F
		add rax, rbx
		xor rbx, rbx
		mov rbx, rax

		cmp bl, 0x09
		jle numl
		add bl, 0x07
		numl:
			add bl, 0x030
		cmp bh, 0x09
		jle numh
		add bh, 0x07
		numh:
			add bh, 0x030

		mov [len], rbx
		rol bx, 8
		mov [plen], rbx

		print plen, 2
		jmp repeat

	choice3:
			;store the string
		pop rax
		push rax
		mov rcx, rax
		mov rsi, buffer
		mov rdi, string
		rep movsb

			;reverse the string
		xor rcx, rcx
		pop rcx
		push rcx
		mov rsi, string
		xor rax, rax
		lea rax, [revstr + rcx - 1]
		mov rdi, rax
		xor rax, rax
		xor rbx, rbx

		reverse:
			mov al, byte[rsi]
			mov byte[rdi], al
			inc rsi
			dec rdi
		loop reverse

		print response2, lresponse2
		print revstr, len
		jmp repeat


	choice4:
			;check for palindrome
		xor rcx, rcx
		pop rcx
		push rcx
		mov rsi, string
		mov rdi, revstr
		xor rax, rax

		check:
			mov al, byte[rsi]
			cmp byte[rdi], al
			je skip
			jmp ntpal
			skip:
				inc rsi
				inc rdi
		loop check

		print option1, loption1
		jmp repeat

		ntpal:
		print option2, loption2
		jmp repeat

	exit:
		mov rax, 0x3C
		mov rdi, 0
		syscall
