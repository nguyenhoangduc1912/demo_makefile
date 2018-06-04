#makefile

PRO_DIR := .
PROJ_NAME	:= demo_sum
OUTPUT_PATH := $(PRO_DIR)/output

SRC_DIR := $(PRO_DIR)/src

COMPILER_DIR 		:= C:/tools/gcc_7_2017_q4_major
PREFIX_GCC_COMPILER := arm-none-eabi

CC				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-gcc

CC_OPT			:= -march=armv6-m -mcpu=cortex-m0 -c -O0 -g -mthumb

build: $(SRC_DIR)/main.c
	$(CC) $(CC_OPT) $(SRC_DIR)/main.c -o $(OUTPUT_PATH)/$(PROJ_NAME).exe
	
clean:
	@rm -rf $(OUTPUT_PATH)/*