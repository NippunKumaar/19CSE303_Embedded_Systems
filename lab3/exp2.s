 AREA data,DATA,READONLY
num dcb 0x01, 0x02, 0x03, 0x04
len dcb 0x4

 AREA data1,DATA,READWRITE
result dcd 0x00

 AREA exp2, CODE, READONLY
 ldr r1, =num
 ldr r2, =len
 ldr r3, =result
 mov r4, #0			;intializing the result register
 ldr r5, [r2]		;loading len
adding ldrb r6, [r1]		;loading a byte for addition
 add r4,r4,r6		; adding the byte
 add r1, r1, #0x01	; incrementing the address to point to next byte
 sub r5, r5, #0x01	; decrementing length by 1
 cmp r5, #0x00		; checking for length to be zero
 bne adding
 str r4, [r3]
e b e

 end

