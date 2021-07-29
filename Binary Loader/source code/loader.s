/* by MaTiAz :) */

.set noat
.set noreorder

/* gripshift text address is 0x08804000 */

/* i can has nopsled lol */
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop

/*sceIoOpen: Gripshift.text_addr + 0x187B10 */
addiu $a0, $ra, 0xC0	/* filename, plz2hex in the file yourself, offset 0x168 */
nop
li $a1, 1
li $a2, 31
jal 0x08A6985C		/* sceIoOpen */
nop

move $a0, $v0		/* set the return value of the function for arg0 of the next function */

lui $a1, 0x0881		/* arg1 is 0x08810000, load address of the binary file */
lui $a2, 1		/* arg2, read 0x10000 bytes from the file */
jal 0x08A697FC		/* sceIoRead */
nop

jal 0x08A69854		/* sceIoClose */
nop

lui $a0, 0x0881
lui $a1, 0x1
jal 0x08A6965C		/* sceKernelDcacheInvalidateRange */
nop

nop
nop
li $a0, 0x08810000
jr $a0
nop

