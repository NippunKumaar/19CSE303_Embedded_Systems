 AREA data, DATA, READONLY
string dcb "Amrita school\0"

 AREA data1, DATA, READWRITE
destination dcd 0

 AREA exp1, CODE, READONLY
 ldr r0, =string
 ldr r1, =destination
 mov r3, #0				; Intializing position counter
loop ldrb r2, [r0], #1
 add r3, r3, #1
 cmp r2, #" "
 beq exit 
 cmp r2, #"\0"
 moveq r3, #-1
 bne loop
exit str r3, [r1]
e b e
 end