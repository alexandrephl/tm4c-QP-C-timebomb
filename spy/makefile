################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /Applications/TI/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Application/bsp.o" \
"./Application/main.o" \
"./QPC/qep_hsm.o" \
"./QPC/qep_msm.o" \
"./QPC/qf_act.o" \
"./QPC/qf_actq.o" \
"./QPC/qf_defer.o" \
"./QPC/qf_dyn.o" \
"./QPC/qf_mem.o" \
"./QPC/qf_ps.o" \
"./QPC/qf_qact.o" \
"./QPC/qf_qeq.o" \
"./QPC/qf_qmact.o" \
"./QPC/qf_time.o" \
"./QPC/qv.o" \
"./QPC_ports/qv_port.o" \
"./QS/qs.o" \
"./QS/qs_64bit.o" \
"./QS/qs_fp.o" \
"./QS/qs_rx.o" \
"./QS/qstamp.o" \
"./QS/qutest.o" \
"./ek-tm4c123gxl/startup_TM4C123GH6PM.o" \
"./ek-tm4c123gxl/system_TM4C123GH6PM.o" \
-Wl,-T"../lesson.ld" \
$(GEN_CMDS__FLAG) \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Application/subdir_vars.mk
-include QPC/subdir_vars.mk
-include QPC_ports/subdir_vars.mk
-include QS/subdir_vars.mk
-include ek-tm4c123gxl/subdir_vars.mk
-include subdir_rules.mk
-include Application/subdir_rules.mk
-include QPC/subdir_rules.mk
-include QPC_ports/subdir_rules.mk
-include QS/subdir_rules.mk
-include ek-tm4c123gxl/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Lesson46.out 

EXE_OUTPUTS__QUOTED += \
"Lesson46.out" 


# All Target
all: $(OBJS) $(LD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Lesson46.out"

# Tool invocations
Lesson46.out: $(OBJS) $(LD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"/Applications/TI/ccs/tools/compiler/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-gcc-9.2.1" -mfpu=fpv4-sp-d16 -DTM4C123GH6PM -DQ_SPY -O0 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -mcpu=cortex-m4 -Wl,-Map,"Lesson46.map" -mfloat-abi=hard -mfpu=fpv4-sp-d16 -specs=nano.specs -specs=nosys.specs -o"Lesson46.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "Application/bsp.o" "Application/main.o" "QPC/qep_hsm.o" "QPC/qep_msm.o" "QPC/qf_act.o" "QPC/qf_actq.o" "QPC/qf_defer.o" "QPC/qf_dyn.o" "QPC/qf_mem.o" "QPC/qf_ps.o" "QPC/qf_qact.o" "QPC/qf_qeq.o" "QPC/qf_qmact.o" "QPC/qf_time.o" "QPC/qv.o" "QPC_ports/qv_port.o" "QS/qs.o" "QS/qs_64bit.o" "QS/qs_fp.o" "QS/qs_rx.o" "QS/qstamp.o" "QS/qutest.o" "ek-tm4c123gxl/startup_TM4C123GH6PM.o" "ek-tm4c123gxl/system_TM4C123GH6PM.o" 
	-$(RM) "Application/bsp.d" "Application/main.d" "QPC/qep_hsm.d" "QPC/qep_msm.d" "QPC/qf_act.d" "QPC/qf_actq.d" "QPC/qf_defer.d" "QPC/qf_dyn.d" "QPC/qf_mem.d" "QPC/qf_ps.d" "QPC/qf_qact.d" "QPC/qf_qeq.d" "QPC/qf_qmact.d" "QPC/qf_time.d" "QPC/qv.d" "QPC_ports/qv_port.d" "QS/qs.d" "QS/qs_64bit.d" "QS/qs_fp.d" "QS/qs_rx.d" "QS/qstamp.d" "QS/qutest.d" "ek-tm4c123gxl/startup_TM4C123GH6PM.d" "ek-tm4c123gxl/system_TM4C123GH6PM.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

