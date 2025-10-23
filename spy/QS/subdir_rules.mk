################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
QS/%.o: ../QS/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/Applications/TI/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gcc-9.2.1" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DTM4C123GH6PM -DQ_SPY -I"/Users/alexandrepanhaleux/Developer/CCS_Workspace/Lesson46/ek-tm4c123gxl" -I"/Users/alexandrepanhaleux/Developer/CCS_Workspace/Lesson46/qpc/include" -I"/Users/alexandrepanhaleux/Developer/CCS_Workspace/Lesson46/qpc/ports/arm-cm/qv/gnu" -I"/Users/alexandrepanhaleux/Developer/CCS_Workspace/Lesson46/CMSIS/Include" -I"/Users/alexandrepanhaleux/Developer/CCS_Workspace/Lesson46" -I"/Users/alexandrepanhaleux/Developer/CCS_Workspace/Lesson46/Application" -I"/Applications/TI/TivaWare-2.2.0.295" -O0 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"QS/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


