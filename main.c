#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "cpu.h"
#include "memory.h"
#include "disasm.h"



int main(){
    
    struct CPU cpu;
    uint8_t *memory = mem_create();
    cpu_init(&cpu, MEM_SIZE);
    

    // mov eax, 5
    memory[0] = 0xB8;
    memory[1] = 0x05;
    memory[2] = 0x00;
    memory[3] = 0x00;
    memory[4] = 0x00;
    
    // mov ecx, 5
    memory[5] = 0xB9;
    memory[6] = 0x05;
    memory[7] = 0x00;
    memory[8] = 0x00;
    memory[9] = 0x00;
    
    // cmp eax, ecx
    memory[10] = 0x39;
    memory[11] = 0xC8;
    
    // inc eax
    memory[12] = 0x40;
    // dec eax
    memory[13] = 0x48;
    
    // add eax, ecx
    memory[14] = 0x01;
    memory[15] = 0xC8;
    
    // sub eax, ecx
    memory[16] = 0x29;
    memory[17] = 0xC8;
    
    // add eax, imm
    memory[18] = 0x05;
    memory[19] = 0x05;
    memory[20] = 0x00;
    memory[21] = 0x00;
    memory[22] = 0x00;
    
     // mov ecx, eax
    memory[23] = 0x89;
    memory[24] = 0xC1;
    
    // cmp eax, ecx
    memory[25] = 0x39;
    memory[26] = 0xC8;
    
    // xor eax, eax
    memory[27] = 0x31;
    memory[28] = 0xC0;
  
    // mov ecx, eax
    memory[29] = 0x8B;
    memory[30] = 0xC1;

    // add eax, 0x05
    memory[31] = 0x83;
    memory[32] = 0xC0;
    memory[33] = 0x05;

    // sub eax, 0x02
    memory[34] = 0x83;
    memory[35] = 0xE8;
    memory[36] = 0x02;
 
    // cmp eax, 0x03
    memory[37] = 0x83;
    memory[38] = 0xF8;
    memory[39] = 0x03;

    // jne +4
    memory[40] = 0x75;
    memory[41] = 0x04;

    // add eax, 0x10
    memory[42] = 0x83;
    memory[43] = 0xC0;
    memory[44] = 0x10;

    // nop
    memory[45] = 0x90;

    // jmp -10 bytes
    memory[46] = 0xEB;
    memory[47] = (int8_t)-10;
    
    // HLT
    memory[48] = 0xF4;



    
    while(1){
        cpu_step(&cpu, memory);
        disassemble(memory, cpu.eip);
        //print_state(&cpu);

     
        if(cpu.eip >= MEM_SIZE || memory[cpu.eip] == 0xF4) break; 
    }

    return 0;
}

