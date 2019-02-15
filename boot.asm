[BITS 16]
[ORG 0x7c00]	;First instruction adress

global loader

mov ax, 0x0003  ; 80x25 16color mode
int 0x10		; video interrupt

xor ax, ax
mov ah, 0x01
mov cx, 0x2607
int 0x10

mov ax, 0x1003
mov bx, 0
int 0x10

xor ax, ax
mov ss, ax
mov sp, 0x7c00

reset_drive:
  mov ah, 0
  int 0x13
  or ah, ah
  jnz reset_drive

  ; load from disk
	xor ax, ax
	mov es, ax
	mov ch, ah
	mov dh, ah
	mov bx, 0x7e00
	mov cl, 0x02
	mov ah, 0x02
	mov al, 0x0A
	int 0x13 ; to the designer of this interruption:
			 ; i fucking hate you
	or ah, ah
	jnz reset_drive

  cli ; disable iterrupts

  ; set the ds register
  xor ax, ax
  mov ds, ax

  lgdt [gtd_desc] ; load segments table

  ; go to protected mode
  mov eax, cr0
  or eax, 0x01
  mov cr0, eax

  jmp 0x08:clear_pipe32 ; go to 32-bit code

;section .data ; this was added
[BITS 32]
clear_pipe32:
  mov ax , 0x10   
  mov ds , ax          
  mov ss , ax          
  mov es , ax
  mov fs , ax
  mov gs , ax
  mov ebp , 0x90000
  mov esp , ebp

  mov byte [0xB8000], 88
  mov byte [0xB8000+1], 0x1B

  loader:
  call dword 0x08:0x07e00 ; go to C code

  mov byte [0xB8000+4], 89
  mov byte [0xB8000+5], 0x1B
  jmp $

[BITS 64]
clear_pipe64:
  ; set segment registers
  mov ax , 0x10   
  mov ds , ax          
  mov ss , ax          
  mov es , ax
  mov fs , ax
  mov gs , ax
  mov ebp , 0x90000    
  mov esp , ebp

  mov byte [0xB8000], 88
  mov byte [0xB8000+1], 0x1B

  ;call qword 0x08:0x01000 ; go to C code

  mov byte [0xB8000+4], 89
  mov byte [0xB8000+5], 0x1B
  jmp $


gdt:

gdt_null:
  dd 0
  dd 0

gdt_code:
  dw 0xFFFF
  dw 0
  db 0
  db 10011010b
  db 11001111b
  db 0

gdt_data:
  dw 0xFFFF
  dw 0
  db 0
  db 10010010b
  db 11001111b
  db 0

gdt_end:

gtd_desc:
   dw gdt_end - gdt - 1
   dd gdt

TIMES 510 - ($ - $$) db 0	; Fill the rest of sector with 0
DW 0xAA55 ; Add boot signature at the end of bootloader
