################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Inc/CAN/CAN.cpp 

OBJS += \
./Inc/CAN/CAN.o 

CPP_DEPS += \
./Inc/CAN/CAN.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/CAN/CAN.o: ../Inc/CAN/CAN.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F303x8 -DCAN -c -I../Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Inc/CAN/CAN.d" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

