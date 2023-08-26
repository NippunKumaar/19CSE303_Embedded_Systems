 AREA exp1, CODE, READONLY

 mov r1, #0x04			; Data (Change this for different test case)
 ands r1, r1, #0x03		; and masing with setting condition codes. Mask value is 0x03
 moveq r2, #0xFF
 movne r2, #0xAA
e b e
 end 