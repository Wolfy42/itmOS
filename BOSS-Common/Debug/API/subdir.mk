################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../API/systemCalls.cpp 

CPP_DEPS += \
./API/systemCalls.pp 

OBJS += \
./API/systemCalls.obj 

CPP_DEPS__QUOTED += \
"API/systemCalls.pp" 

OBJS__QUOTED += \
"API/systemCalls.obj" 

CPP_SRCS__QUOTED += \
"../API/systemCalls.cpp" 


# Each subdirectory must supply rules for building sources it contributes
API/systemCalls.obj: ../API/systemCalls.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: TMS470 Compiler'
	"/usr/local/CCSv5/ccsv5/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="/usr/local/CCSv5/ccsv5/tools/compiler/tms470/include" --include_path="/home/stefan/BeagleBoard/itmOS/BOSS-Common"  --diag_warning=225 -me --enum_type=packed --abi=ti_arm9_abi --code_state=32 --preproc_with_compile --preproc_dependency="API/systemCalls.pp"  --obj_directory="API" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


