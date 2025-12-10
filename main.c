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
    

    FILE *f = fopen("test.bin", "rb");
    if(!f) {
       printf("Erro ao abrir arquivo\n");
       return -1;
    }
    fseek(f, 0, SEEK_END);
    long t = ftell(f);
    rewind(f);

    fread(memory, 1, t, f);
    fclose(f);
    while(1){
        cpu_step(&cpu, memory);
        disassemble(memory, cpu.eip);
        //print_state(&cpu);

     
        if(cpu.eip >= MEM_SIZE || memory[cpu.eip] == 0xF4) break; 
    }

    return 0;
}

