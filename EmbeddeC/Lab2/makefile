#@Copyrights $(Project Name) ashraf
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIB= 
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project Name=app


all: $(Project Name).hex
	@echo "Build is finished $(Project Name)"


#%.o: %.s
#	$(CC)as.exe $(CFLAGS) $< -o $@	

%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@

$(Project Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linkerscript.ld $(LIB) $(OBJ) -o $@ -Map=Map_file_$(Project Name).map	


$(Project Name).hex: $(Project Name).elf
	$(CC)objcopy.exe -O binary $< $@


clear_all:
	rm *.o *.elf *.hex

