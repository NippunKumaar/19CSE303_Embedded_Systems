 AREA data, DATA, READONLY
num dcd 1, 2, 3, -4
len dcd 4

 AREA data1, DATA, READWRITE
result dcw 0

 AREA exp1, CODE, READONLY
 ldr r1, =num
 ldr r2, =len
 ldr r3, =result
 mov r4, #0			;intializing the result register
 ldr r5, [r2]		;loading len
loading ldr r6, [r1]		;loading a byte for addition
 movs r6, r6				; setting flags
 addmi r4, r4, #1			; Checking N-flag
 add r1, r1, #0x04	; incrementing the address to point to next byte
 sub r5, r5, #0x01	; decrementing length by 1
 cmp r5, #0x00		; checking for length to be zero
 bne loading
 str r4, [r3]
e b e

 end
