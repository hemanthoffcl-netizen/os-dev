# Building HimayOS on Windows

## Option 1: WSL2 (Recommended)

### Step 1: Install WSL2

Open PowerShell as Administrator and run:

```powershell
wsl --install
```

Restart your computer, then launch Ubuntu from the Start menu.

### Step 2: Install Dependencies in WSL

```bash
sudo apt update
sudo apt install -y nasm qemu-system-x86 grub-pc-bin xorriso wget make
```

### Step 3: Install Cross-Compiler

**Option A: Use Prebuilt Toolchain (Easier)**

```bash
cd ~
wget https://github.com/ISIPP/x86-cross-compiler/releases/download/v1.0/i686-elf-tools-linux-x86_64.tar.gz
tar -xzf i686-elf-tools-linux-x86_64.tar.gz
export PATH=$HOME/i686-elf-tools/bin:$PATH
```

Add to ~/.bashrc for persistence:
```bash
echo 'export PATH=$HOME/i686-elf-tools/bin:$PATH' >> ~/.bashrc
source ~/.bashrc
```

**Option B: Build Cross-Compiler (Advanced)**

Follow the OSDev wiki: https://wiki.osdev.org/GCC_Cross-Compiler

### Step 4: Build the OS

```bash
cd /mnt/c/Users/himay/os-dev
make
```

### Step 5: Run in QEMU

```bash
make run
```

---

## Option 2: Pre-built Environment

If you have a Linux VM or dual-boot, copy the `os-dev` folder there and run `make`.

---

## Troubleshooting

**Error: i686-elf-gcc not found**
- Ensure cross-compiler is in your PATH
- Verify with: `i686-elf-gcc --version`

**Error: grub-mkrescue not found**
- Install: `sudo apt install grub-pc-bin`

**Error: linker script issues**
- Make sure you're using i686-elf-gcc, not system gcc
