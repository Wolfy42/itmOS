################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Lib/Rand.cpp \
../Lib/Time.cpp \
../Lib/bitOperations.cpp \
../Lib/hexOperations.cpp 

CPP_DEPS += \
./Lib/Rand.pp \
./Lib/Time.pp \
./Lib/bitOperations.pp \
./Lib/hexOperations.pp 

OBJS += \
./Lib/Rand.obj \
./Lib/Time.obj \
./Lib/bitOperations.obj \
./Lib/hexOperations.obj 

OBJS__QTD += \
".\Lib\Rand.obj" \
".\Lib\Time.obj" \
".\Lib\bitOperations.obj" \
".\Lib\hexOperations.obj" 

CPP_DEPS__QTD += \
".\Lib\Rand.pp" \
".\Lib\Time.pp" \
".\Lib\bitOperations.pp" \
".\Lib\hexOperations.pp" 

CPP_SRCS_QUOTED += \
"../Lib/Rand.cpp" \
"../Lib/Time.cpp" \
"../Lib/bitOperations.cpp" \
"../Lib/hexOperations.cpp" 


# Each subdirectory must supply rules for building sources it contributes
Lib/Rand.obj: ../Lib/Rand.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="C:/Users/root/Documents/itmOS/BOSS-Common" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="Lib/Rand.pp" --obj_directory="Lib" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Lib/Time.obj: ../Lib/Time.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="C:/Users/root/Documents/itmOS/BOSS-Common" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="Lib/Time.pp" --obj_directory="Lib" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Lib/bitOperations.obj: ../Lib/bitOperations.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="C:/Users/root/Documents/itmOS/BOSS-Common" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="Lib/bitOperations.pp" --obj_directory="Lib" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Lib/hexOperations.obj: ../Lib/hexOperations.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/tms470/include" --include_path="C:/Users/root/Documents/itmOS/BOSS-Common" --diag_warning=225 -me --enum_type=packed --code_state=32 --preproc_with_compile --preproc_dependency="Lib/hexOperations.pp" --obj_directory="Lib" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


