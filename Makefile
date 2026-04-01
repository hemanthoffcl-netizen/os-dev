CC = i686-elf-gcc
LD = i686-elf-ld
ASM = nasm
CFLAGS = -ffreestanding -m32 -O2 -Wall -Wextra -I./include
LDFLAGS = -m elf_i386 -T linker.ld --oformat binary
ASMFLAGS = -f elf32

KERNEL_SRC = src/kernel/kernel.c src/kernel/vga.c src/kernel/idt.c src/kernel/keyboard.c src/kernel/shell.c src/kernel/idt_handler.c src/kernel/pic.c
KERNEL_OBJ = $(KERNEL_SRC:.c=.o)
BOOT_OBJ = src/boot/boot.o src/boot/multiboot_header.o src/boot/pic.o

all: kernel.iso

kernel.bin: $(BOOT_OBJ) $(KERNEL_OBJ)
	$(LD) $(LDFLAGS) -o kernel.bin $(BOOT_OBJ) $(KERNEL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

kernel.iso: kernel.bin
	cp kernel.bin isodir/boot/kernel.bin
	grub-mkrescue -o kernel.iso isodir

run: kernel.iso
	qemu-system-i386 -cdrom kernel.iso -m 512M

clean:
	rm -f $(BOOT_OBJ) $(KERNEL_OBJ) kernel.bin kernel.iso
	rm -rf isodir/boot/kernel.bin
