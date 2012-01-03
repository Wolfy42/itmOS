################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Messaging/MemoryManager/MemoryManager.cpp 

CPP_DEPS += \
./Messaging/MemoryManager/MemoryManager.pp 

OBJS += \
./Messaging/MemoryManager/MemoryManager.obj 

CPP_DEPS__QUOTED += \
"Messaging/MemoryManager/MemoryManager.pp" 

OBJS__QUOTED += \
"Messaging/MemoryManager/MemoryManager.obj" 

CPP_SRCS__QUOTED += \
"../Messaging/MemoryManager/MemoryManager.cpp" 


# Each subdirectory must supply rules for building sources it contributes
Messaging/MemoryManager/MemoryManager.obj: ../Messaging/MemoryManager/MemoryManager.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: TMS470 Compiler'
	"/usr/local/CCSv5/ccsv5/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="/usr/local/CCSv5/ccsv5/tools/compiler/tms470/include" --include_path="/home/stefan/BeagleBoard/itmOS/BOSS-Common"  --diag_warning=225 -me --enum_type=packed --abi=ti_arm9_abi --code_state=32 --preproc_with_compile --preproc_dependency="Messaging/MemoryManager/MemoryManager.pp"  --obj_directory="Messaging/MemoryManager" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


