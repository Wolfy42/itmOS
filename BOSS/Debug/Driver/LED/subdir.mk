################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Driver/LED/LEDDriver.cpp 

CPP_DEPS += \
./Driver/LED/LEDDriver.pp 

OBJS += \
./Driver/LED/LEDDriver.obj 

OBJS__QTD += \
".\Driver\LED\LEDDriver.obj" 

CPP_DEPS__QTD += \
".\Driver\LED\LEDDriver.pp" 

CPP_SRCS_QUOTED += \
"../Driver/LED/LEDDriver.cpp" 


# Each subdirectory must supply rules for building sources it contributes
Driver/LED/LEDDriver.obj: ../Driver/LED/LEDDriver.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="Driver/LED/LEDDriver.pp" --obj_directory="Driver/LED" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


