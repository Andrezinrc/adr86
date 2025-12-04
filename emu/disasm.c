#include "disasm.h"
#include "memory.h"
#include <stdio.h>



void disassemble(uint8_t *memory, uint32_t eip) {
    uint8_t op = memory[eip];

    switch (op) {
        case 0xB8: printf("mov eax, 0x%08X\n",
                          mem_read32(memory, eip+1)); break;
        case 0xB9: printf("mov ecx, 0x%08X\n",
                          mem_read32(memory, eip+1)); break;
        case 0x39: printf("cmp eax, ecx\n"); break;
        case 0x40: printf("inc eax\n"); break;
        case 0x48: printf("dec eax\n"); break;
        case 0x01: printf("add eax, ecx\n"); break;
        case 0x29: printf("sub eax, ecx\n"); break;
        case 0x05: printf("add eax, 0x%08X\n",
                          mem_read32(memory, eip+1)); break;
        case 0x89: {
            uint8_t modrm = memory[eip+1];
            if(modrm == 0xC1) printf("mov ecx, eax\n");
            break;
        }
        case 0xF4: printf("hlt\n"); break;
        default: printf("db 0x%02X\n", op);
    }
}

