################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Messaging/Message/Message.cpp 

CPP_DEPS += \
./Messaging/Message/Message.pp 

OBJS += \
./Messaging/Message/Message.obj 

OBJS__QTD += \
".\Messaging\Message\Message.obj" 

CPP_DEPS__QTD += \
".\Messaging\Message\Message.pp" 

CPP_SRCS_QUOTED += \
"../Messaging/Message/Message.cpp" 


# Each subdirectory must supply rules for building sources it contributes
Messaging/Message/Message.obj: ../Messaging/Message/Message.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="C:/Users/root/Documents/itmOS/BOSS-Common" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="Messaging/Message/Message.pp" --obj_directory="Messaging/Message" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


