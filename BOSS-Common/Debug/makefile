################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)

ORDERED_OBJS += \
"./API/systemCalls.obj" \
"./Lib/hexOperations.obj" \
"./Lib/bitOperations.obj" \
"./Lib/Time.obj" \
"./Lib/Rand.obj" \
"./Messaging/MemoryManager/MemoryManager.obj" \
"./Messaging/Message/Message.obj" \
"./Messaging/MessageQueue/MessageQueue.obj" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Messaging/MessageQueue/subdir.mk
-include Messaging/Message/subdir.mk
-include Messaging/MemoryManager/subdir.mk
-include Lib/subdir.mk
-include API/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: BOSS-Common.lib

# Tool invocations
BOSS-Common.lib: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Archiver'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/ar470" r "BOSS-Common.lib" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(TMS470_LIBRARY_OUTPUTS__QTD) "BOSS-Common.lib"
	-$(RM) ".\Messaging\MessageQueue\MessageQueue.obj" ".\Messaging\Message\Message.obj" ".\Messaging\MemoryManager\MemoryManager.obj" ".\Lib\Rand.obj" ".\Lib\Time.obj" ".\Lib\bitOperations.obj" ".\Lib\hexOperations.obj" ".\API\systemCalls.obj" 
	-$(RM) ".\Messaging\MessageQueue\MessageQueue.pp" ".\Messaging\Message\Message.pp" ".\Messaging\MemoryManager\MemoryManager.pp" ".\Lib\Rand.pp" ".\Lib\Time.pp" ".\Lib\bitOperations.pp" ".\Lib\hexOperations.pp" ".\API\systemCalls.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
