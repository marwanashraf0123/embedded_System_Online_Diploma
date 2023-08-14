#@Copyrights marwan ashraf
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIB= 
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)

all: marwan.bin
	@echo "Build is finished marwan"


%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@	

%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@

marwan.elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linkerscript.ld $(LIB) $(OBJ) -o $@ -Map=Map_file_marwan.map	


marwan.bin: marwan.elf
	$(CC)objcopy.exe -O binary $< $@


clear_all:
	rm *.o *.elf *.bin

