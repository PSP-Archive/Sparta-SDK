/* by FreePlay :) */

.set noreorder
 
li $v0, 0x44000000
li $a0, 0xFFFFFFFF
li $a1, 0x00000000
 
nop
 
dowhite:
 
li $v0, 0x44000000
nop
 
loopwhite:
sw $a0, 0($v0)
addiu $v0, $v0, 4
bgeu $v0, 0x44200000, doblack
nop
b loopwhite
nop
 
doblack:

li $v0, 0x44000000

sw $a1, 0x0($v0)
sw $a1, 0x400($v0)
sw $a1, 0x40C($v0)
sw $a1, 0x410($v0)
sync
sw $a1, 0x414($v0)
sw $a1, 0x808($v0)
sw $a1, 0x824($v0)
sw $a1, 0x830($v0)
sync
sw $a1, 0x840($v0)
sw $a1, 0x848($v0)
sw $a1, 0x84C($v0)
sw $a1, 0xC0C($v0)
sync
sw $a1, 0xC10($v0)
sw $a1, 0xC14($v0)
sw $a1, 0xC24($v0)
sw $a1, 0xC30($v0)
sync
sw $a1, 0xC40($v0)
sw $a1, 0xC44($v0)
sw $a1, 0xC50($v0)
sw $a1, 0x1018($v0)
sync
sw $a1, 0x1024($v0)
sw $a1, 0x1030($v0)
sw $a1, 0x1040($v0)
sw $a1, 0x1048($v0)
sync
sw $a1, 0x104C($v0)
sw $a1, 0x140C($v0)
sw $a1, 0x1410($v0)
sw $a1, 0x1414($v0)
sync
sw $a1, 0x1428($v0)
sw $a1, 0x142C($v0)
sw $a1, 0x1434($v0)
sw $a1, 0x1440($v0)
sync

stayhere:
b stayhere
nop
