lw $1, 0($0)
lw $2, 4($0)
lw $3, 8($0)
add $4, $1, $2
beq $3, $4, 2
add $4, $4, $4
sw $4, 12($0)
