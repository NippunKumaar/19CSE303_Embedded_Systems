 AREA data, DATA, READONLY
string dcb "Amrita\0"

 AREA data1, DATA, READWRITE
length dcd 0

 AREA exp1, CODE, READONLY
 ldr r0, =string
 ldr r1, =length
 mov r3, #0				; Intializing length register
loop ldrb r2, [r0], #1
 cmp r2, #"\0"
 addne r3, r3, #1
 bne loop
 str r3, [r1]
e b e
 end