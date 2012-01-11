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

OBJS__QTD += \
".\API\systemCalls.obj" 

CPP_DEPS__QTD += \
".\API\systemCalls.pp" 

CPP_SRCS_QUOTED += \
"../API/systemCalls.cpp" 


# Each subdirectory must supply rules for building sources it contributes
API/systemCalls.obj: ../API/systemCalls.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="C:/Users/root/Documents/itmOS/BOSS-Common" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="API/systemCalls.pp" --obj_directory="API" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


