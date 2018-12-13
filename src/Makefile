
main.o: main.c
	avr-gcc -O2 -Wall -g -mmcu=atmega16u2 -c main.c

main.elf: main.o
	avr-gcc -g -mmcu=atmega16u2 -o main.elf main.o

main.hex: main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
