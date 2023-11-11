#*******************************************************************
# *  FILE DESCRIPTION
#-----------------------
# *  Author:  Khaled El-Sayed (@t0ti20)
# *  Created:  05.02.2023
# *  File:  Makefile
# *  Module:  Global
# *  Description:  Make File For Auto Generation
#*******************************************************************
#Compiler Name
CC=arm-none-eabi-
#Compiler Flags
CFLAGS= -mcpu=cortex-m3 -mthumb -O0 -W -Wall --std=gnu99 -fgnu89-inline -g --specs=nosys.specs -gdwarf-4
#Asseemb Flags
AFLAGS= -g -gdwarf-4
#Linker Flags
LFLAGS= -O0 -W -Wall --std=gnu99 -mthumb -fgnu89-inline -mcpu=cortex-m3 --specs=nosys.specs --specs=nano.specs -lc -Wl,-Map=Map_File.map -g -gdwarf-4
INCS= \
		-I ./Library/Cortex_M3/Headers/
LIBS= 
LOCA= ./Application
#*******************************************************************
#*******************************************************************
# (@)					-hide command
# (%.o)					-all object files
# $(CC)					-replace variable
# ($<)					-One Dependency at time
# ($@)					-One Output at time
# ($(wildcard *.c))		-all fiiles .c
# $(CC)					-replace variable
#Generate Hex File
#*******************************************************************
#*******************************************************************
SRC=$(shell find $(SOURCEDIR) -name '*.c')
SRS=$(shell find $(SOURCEDIR) -name '*.s')
SRL=$(shell find $(SOURCEDIR) -name '*.ld')
INCS += $(shell find $(SOURCEDIR) -name '*.h' -exec dirname {} \; | uniq | sed 's/^/-I /')
OBJ=$(SRC:.c=.o) $(SRS:.s=.o)	
Application=STM32F103C8
#*******************************************************************
#*******************************************************************
Make: $(Application).hex
	@find $(SOURCEDIR) -path ./Debug -prune -o -type f -iname '*.map' -exec mv -t Debug {} +
	@find $(SOURCEDIR) -path ./Debug -prune -o -type f -iname '*.o' -exec mv -t Debug {} +
	@cp ./Debug/$(Application).elf ./Debug/$(Application).axf 
	@echo "========== Build Finished ========="
#Compile And Assimble C Files Files
%.o:%.c
	@$(CC)gcc $(CFLAGS) -c $< $(INCS) -o $@
#Assimble Assimply Files
%.o:%.s
	@$(CC)as  -o $@ $< 
#Link All Files And Generate ELF File
$(Application).elf: $(OBJ)
	@$(CC)gcc $(OBJ) $(INCS) $(CFLAGS) -T $(SRL)  $(LIBS) -o ./Debug/$@ 
#Generate Hex File
$(Application).hex: $(Application).elf
	@$(CC)objcopy -O ihex ./Debug/$< ./Debug/$@ 
#Clean All Files
clean:
	@find $(SOURCEDIR) -name '*.axf' -exec rm {} \;
	@find $(SOURCEDIR) -name '*.o' -exec rm {} \;
	@find $(SOURCEDIR) -name '*.hex*' -exec rm {} \;
	@find $(SOURCEDIR) -name '*.elf*' -exec rm {} \;
	@find $(SOURCEDIR) -name '*.map' -exec rm {} \;
	@echo "========== Done Cleaning =========="
#*******************************************************************
#*******************************************************************