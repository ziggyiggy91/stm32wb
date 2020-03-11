################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
game_pad.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
game_pad.list \

OBJCOPY_BIN += \
game_pad.bin \


# All Target
all: game_pad.elf secondary-outputs

# Tool invocations
game_pad.elf: $(OBJS) $(USER_OBJS) C:\Users\Ismae\STM32CubeIDE\workspace_1.2.0\game_pad\STM32WB55RGVX_FLASH.ld
	arm-none-eabi-gcc -o "game_pad.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Ismae\STM32CubeIDE\workspace_1.2.0\game_pad\STM32WB55RGVX_FLASH.ld" --specs=nosys.specs -Wl,-Map="game_pad.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

game_pad.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "game_pad.list"
	@echo 'Finished building: $@'
	@echo ' '

game_pad.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "game_pad.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
