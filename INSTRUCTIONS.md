# Implemented Instructions

0xB8    mov eax, imm32
0xB9    mov ecx, imm32
0x40    inc eax
0x48    dec eax
0x01    add r/m32, r32
0x29    sub r/m32, r32
0x05    add eax, imm32
0x31    xor eax, eax
0x89    mov r/m32, r32
0x8B    mov r32, r/m32
0x83    grp1 (add/sub/cmp imm8)
0x75    jne rel8
0xEB    jmp rel8
0x90    nop
0xF4    hlt
