################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./Driver/Driver.obj" \
"./Driver/LED/LEDDriver.obj" \
"./HAL/LED/LED.obj" \
"./HAL/LED/HalLedDriver.obj" \
"./Kernel/TaskManagement/Scheduler/Scheduler.obj" \
"./Kernel/TaskManagement/Task/TaskControlBlock.obj" \
"./Kernel/TaskManagement/Task/Task.obj" \
"./Kernel/TaskManagement/TaskManager.obj" \
-l"libc.a" \
"../beagle.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Kernel/TaskManagement/subdir.mk
-include Kernel/TaskManagement/Task/subdir.mk
-include Kernel/TaskManagement/Scheduler/subdir.mk
-include HAL/LED/subdir.mk
-include Driver/LED/subdir.mk
-include Driver/subdir.mk
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
all: BOSS.out

# Tool invocations
BOSS.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --diag_warning=225 -me --enum_type=packed --code_state=32 -z -m"BOSS.map" --warn_sections -i"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/lib" -i"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --reread_libs --rom_model -o "BOSS.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(TMS470_EXECUTABLE_OUTPUTS__QTD) "BOSS.out"
	-$(RM) ".\Kernel\TaskManagement\TaskManager.obj" ".\Kernel\TaskManagement\Task\Task.obj" ".\Kernel\TaskManagement\Task\TaskControlBlock.obj" ".\Kernel\TaskManagement\Scheduler\Scheduler.obj" ".\HAL\LED\HalLedDriver.obj" ".\HAL\LED\LED.obj" ".\Driver\LED\LEDDriver.obj" ".\Driver\Driver.obj" 
	-$(RM) ".\Kernel\TaskManagement\TaskManager.pp" ".\Kernel\TaskManagement\Task\Task.pp" ".\Kernel\TaskManagement\Task\TaskControlBlock.pp" ".\Kernel\TaskManagement\Scheduler\Scheduler.pp" ".\HAL\LED\HalLedDriver.pp" ".\HAL\LED\LED.pp" ".\Driver\LED\LEDDriver.pp" ".\Driver\Driver.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
