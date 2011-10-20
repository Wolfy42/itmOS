################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Kernel/TaskManagement/Task/Task.cpp \
../Kernel/TaskManagement/Task/TaskControlBlock.cpp 

CPP_DEPS += \
./Kernel/TaskManagement/Task/Task.pp \
./Kernel/TaskManagement/Task/TaskControlBlock.pp 

OBJS += \
./Kernel/TaskManagement/Task/Task.obj \
./Kernel/TaskManagement/Task/TaskControlBlock.obj 

OBJS__QTD += \
".\Kernel\TaskManagement\Task\Task.obj" \
".\Kernel\TaskManagement\Task\TaskControlBlock.obj" 

CPP_DEPS__QTD += \
".\Kernel\TaskManagement\Task\Task.pp" \
".\Kernel\TaskManagement\Task\TaskControlBlock.pp" 

CPP_SRCS_QUOTED += \
"../Kernel/TaskManagement/Task/Task.cpp" \
"../Kernel/TaskManagement/Task/TaskControlBlock.cpp" 


# Each subdirectory must supply rules for building sources it contributes
Kernel/TaskManagement/Task/Task.obj: ../Kernel/TaskManagement/Task/Task.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="Kernel/TaskManagement/Task/Task.pp" --obj_directory="Kernel/TaskManagement/Task" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Kernel/TaskManagement/Task/TaskControlBlock.obj: ../Kernel/TaskManagement/Task/TaskControlBlock.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="Kernel/TaskManagement/Task/TaskControlBlock.pp" --obj_directory="Kernel/TaskManagement/Task" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


