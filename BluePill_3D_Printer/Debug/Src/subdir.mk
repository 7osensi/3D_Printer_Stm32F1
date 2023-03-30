################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_prog.c \
../Src/AFIO_prog.c \
../Src/Delay_Program.c \
../Src/GPIO_prog.c \
../Src/LCD_prog.c \
../Src/RCC_prog.c \
../Src/SD_MODULE_prog.c \
../Src/SPI_prog.c \
../Src/Stepper_prog.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ADC_prog.o \
./Src/AFIO_prog.o \
./Src/Delay_Program.o \
./Src/GPIO_prog.o \
./Src/LCD_prog.o \
./Src/RCC_prog.o \
./Src/SD_MODULE_prog.o \
./Src/SPI_prog.o \
./Src/Stepper_prog.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ADC_prog.d \
./Src/AFIO_prog.d \
./Src/Delay_Program.d \
./Src/GPIO_prog.d \
./Src/LCD_prog.d \
./Src/RCC_prog.d \
./Src/SD_MODULE_prog.d \
./Src/SPI_prog.d \
./Src/Stepper_prog.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC_prog.cyclo ./Src/ADC_prog.d ./Src/ADC_prog.o ./Src/ADC_prog.su ./Src/AFIO_prog.cyclo ./Src/AFIO_prog.d ./Src/AFIO_prog.o ./Src/AFIO_prog.su ./Src/Delay_Program.cyclo ./Src/Delay_Program.d ./Src/Delay_Program.o ./Src/Delay_Program.su ./Src/GPIO_prog.cyclo ./Src/GPIO_prog.d ./Src/GPIO_prog.o ./Src/GPIO_prog.su ./Src/LCD_prog.cyclo ./Src/LCD_prog.d ./Src/LCD_prog.o ./Src/LCD_prog.su ./Src/RCC_prog.cyclo ./Src/RCC_prog.d ./Src/RCC_prog.o ./Src/RCC_prog.su ./Src/SD_MODULE_prog.cyclo ./Src/SD_MODULE_prog.d ./Src/SD_MODULE_prog.o ./Src/SD_MODULE_prog.su ./Src/SPI_prog.cyclo ./Src/SPI_prog.d ./Src/SPI_prog.o ./Src/SPI_prog.su ./Src/Stepper_prog.cyclo ./Src/Stepper_prog.d ./Src/Stepper_prog.o ./Src/Stepper_prog.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

