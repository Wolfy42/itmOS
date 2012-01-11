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

CPP_DEPS__QUOTED += \
"Lib/Rand.pp" \
"Lib/Time.pp" \
"Lib/bitOperations.pp" \
"Lib/hexOperations.pp" 

OBJS__QUOTED += \
"Lib/Rand.obj" \
"Lib/Time.obj" \
"Lib/bitOperations.obj" \
"Lib/hexOperations.obj" 

CPP_SRCS__QUOTED += \
"../Lib/Rand.cpp" \
"../Lib/Time.cpp" \
"../Lib/bitOperations.cpp" \
"../Lib/hexOperations.cpp" 


# Each subdirectory must supply rules for building sources it contributes
Lib/Rand.obj: ../Lib/Rand.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: TMS470 Compiler'
	"/usr/local/CCSv5/ccsv5/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="/usr/local/CCSv5/ccsv5/tools/compiler/tms470/include" --include_path="/home/stefan/BeagleBoard/itmOS/BOSS-Common"  --diag_warning=225 -me --enum_type=packed --abi=ti_arm9_abi --code_state=32 --preproc_with_compile --preproc_dependency="Lib/Rand.pp"  --obj_directory="Lib" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

Lib/Time.obj: ../Lib/Time.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: TMS470 Compiler'
	"/usr/local/CCSv5/ccsv5/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="/usr/local/CCSv5/ccsv5/tools/compiler/tms470/include" --include_path="/home/stefan/BeagleBoard/itmOS/BOSS-Common"  --diag_warning=225 -me --enum_type=packed --abi=ti_arm9_abi --code_state=32 --preproc_with_compile --preproc_dependency="Lib/Time.pp"  --obj_directory="Lib" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

Lib/bitOperations.obj: ../Lib/bitOperations.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: TMS470 Compiler'
	"/usr/local/CCSv5/ccsv5/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="/usr/local/CCSv5/ccsv5/tools/compiler/tms470/include" --include_path="/home/stefan/BeagleBoard/itmOS/BOSS-Common"  --diag_warning=225 -me --enum_type=packed --abi=ti_arm9_abi --code_state=32 --preproc_with_compile --preproc_dependency="Lib/bitOperations.pp"  --obj_directory="Lib" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

Lib/hexOperations.obj: ../Lib/hexOperations.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: TMS470 Compiler'
	"/usr/local/CCSv5/ccsv5/tools/compiler/tms470/bin/cl470" -mv7A8 -g --include_path="/usr/local/CCSv5/ccsv5/tools/compiler/tms470/include" --include_path="/home/stefan/BeagleBoard/itmOS/BOSS-Common"  --diag_warning=225 -me --enum_type=packed --abi=ti_arm9_abi --code_state=32 --preproc_with_compile --preproc_dependency="Lib/hexOperations.pp"  --obj_directory="Lib" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


