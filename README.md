# adr86

adr86 é um emulador x86 32-bit minimal, escrito em C, focado em execução de instruções e entendimento interno de CPU e debug

Compile:

```bash
gcc main.c emu/cpu.c emu/memory.c emu/disasm.c emu/ptrace-fake.c -I emu -o emulator
```

Execute:

```bash
./emulator
```

Projeto voltado a estudo de arquitetura, emulação e debug, não a compatibilidade completa
