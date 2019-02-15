rm *.bin *.img *.o
nasm -f bin boot.asm -o boot.bin
gcc -m32 -fno-PIC -c -ffreestanding main.c -o main.o
gcc -m32 -fno-PIC -c -ffreestanding video.c -o video.o
gcc -m32 -fno-PIC -c -ffreestanding ports.c -o ports.o
gcc -m32 -fno-PIE -Tlink.ld -nostartfiles main.o video.o ports.o -o kernel.elf

objcopy -R .note -R .comment -S -O binary kernel.elf kernel.bin

dd if=/dev/zero of=disk.img bs=1024 count=637

dd if=boot.bin of=disk.img conv=notrunc
dd if=kernel.bin of=disk.img seek=1 conv=notrunc
cp disk.img ../data.bin
