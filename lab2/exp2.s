 AREA exp2, CODE, READONLY

 mov r5, #0x03	  				;data (Change this for different test case)
 mov r2, #0x08	  				;shift counter
 mov r1, #0x00					; intialiazing result register
shift movs r5, r5, lsr #1		; shifting
 addcs r1, r1, #0x01
 sub r2, r2, #0x01				; decrementing shift counter
 cmp r2, #0						; checking counter to be ZERO
 bne shift
e b e
 end