 AREA data, DATA, READONLY
source dcb "Amrita\0"

 AREA data1, DATA, READWRITE
destination dcd 0

 AREA exp1, CODE, READONLY
 ldr r0, =source
 ldr r1, =destination
loop ldrb r2, [r0], #1
 strb r2, [r1], #1
 cmp r2, #"\0"
 bne loop
e b e
 end