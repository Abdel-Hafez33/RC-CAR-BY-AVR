################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/IR\ SENSOR/IR_sensor.c 

OBJS += \
./HAL/IR\ SENSOR/IR_sensor.o 

C_DEPS += \
./HAL/IR\ SENSOR/IR_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/IR\ SENSOR/IR_sensor.o: ../HAL/IR\ SENSOR/IR_sensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"HAL/IR SENSOR/IR_sensor.d" -MT"HAL/IR\ SENSOR/IR_sensor.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


