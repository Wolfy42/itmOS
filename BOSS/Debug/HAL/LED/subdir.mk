################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HAL/LED/HalLedDriver.cpp \
../HAL/LED/LED.cpp 

CPP_DEPS += \
./HAL/LED/HalLedDriver.pp \
./HAL/LED/LED.pp 

OBJS += \
./HAL/LED/HalLedDriver.obj \
./HAL/LED/LED.obj 

OBJS__QTD += \
".\HAL\LED\HalLedDriver.obj" \
".\HAL\LED\LED.obj" 

CPP_DEPS__QTD += \
".\HAL\LED\HalLedDriver.pp" \
".\HAL\LED\LED.pp" 

CPP_SRCS_QUOTED += \
"../HAL/LED/HalLedDriver.cpp" \
"../HAL/LED/LED.cpp" 


# Each subdirectory must supply rules for building sources it contributes
HAL/LED/HalLedDriver.obj: ../HAL/LED/HalLedDriver.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="HAL/LED/HalLedDriver.pp" --obj_directory="HAL/LED" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

HAL/LED/LED.obj: ../HAL/LED/LED.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="HAL/LED/LED.pp" --obj_directory="HAL/LED" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


