################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../aeat9000.c \
../avagossi.c \
../serial_link.c \
../ssi.c 

OBJS += \
./aeat9000.o \
./avagossi.o \
./serial_link.o \
./ssi.o 

C_DEPS += \
./aeat9000.d \
./avagossi.d \
./serial_link.d \
./ssi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Summon Linux GCC C Compiler'
	arm-none-eabi-gcc -I/opt/libopencm3/arm-none-eabi/include/ -O0 -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


