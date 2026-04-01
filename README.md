# HimayOS - Hobby Operating System

A simple hobby OS for x86 in C with a working shell.

## Prerequisites

You'll need:
- `i686-elf-gcc` cross-compiler
- `nasm` assembler
- `qemu-system-i386` emulator
- `grub` (for grub-mkrescue)

### Windows Setup

Install WSL2 or use a Linux VM, then:

```bash
sudo apt-get install nasm qemu-system-x86 grub-pc-bin xorriso
```

For the cross-compiler, follow the OSDev wiki instructions or use a prebuilt toolchain.

## Building

```bash
make
```

## Running

```bash
make run
```

This will launch QEMU with your OS.

## Features

- VGA text mode output (80x25)
- Keyboard input
- Basic shell with commands
- Interrupt handling (IDT)
- PIC initialization

## Shell Commands

- `clear` - Clear screen
- `help` - Show available commands
- `echo <text>` - Print text
- `ver` - Show version

## Project Structure

```
os-dev/
├── src/
│   ├── boot/          # Boot code (assembly)
│   ├── kernel/        # Kernel C code
│   └── drivers/       # Device drivers
├── include/           # Header files
├── linker.ld          # Linker script
└── Makefile
```

## Resources

- [OSDev Wiki](https://wiki.osdev.org/)
- [JamesM's Tutorial](https://web.archive.org/web/20160416231041/http://www.jamesmolloy.co.uk/tutorial_html/)
