################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/BACKUP.c \
../source/FLASH.c \
../source/GPIO.c \
../source/NVHoang12.c \
../source/SREC.c \
../source/UART.c 

C_DEPS += \
./source/BACKUP.d \
./source/FLASH.d \
./source/GPIO.d \
./source/NVHoang12.d \
./source/SREC.d \
./source/UART.d 

OBJS += \
./source/BACKUP.o \
./source/FLASH.o \
./source/GPIO.o \
./source/NVHoang12.o \
./source/SREC.o \
./source/UART.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\Hoang Viet\Documents\MCUXpressoIDE_11.8.0_1165\workspace\NVHoang12\board" -I"C:\Users\Hoang Viet\Documents\MCUXpressoIDE_11.8.0_1165\workspace\NVHoang12\source" -I"C:\Users\Hoang Viet\Documents\MCUXpressoIDE_11.8.0_1165\workspace\NVHoang12" -I"C:\Users\Hoang Viet\Documents\MCUXpressoIDE_11.8.0_1165\workspace\NVHoang12\drivers" -I"C:\Users\Hoang Viet\Documents\MCUXpressoIDE_11.8.0_1165\workspace\NVHoang12\CMSIS" -I"C:\Users\Hoang Viet\Documents\MCUXpressoIDE_11.8.0_1165\workspace\NVHoang12\utilities" -I"C:\Users\Hoang Viet\Documents\MCUXpressoIDE_11.8.0_1165\workspace\NVHoang12\startup" -Os -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/BACKUP.d ./source/BACKUP.o ./source/FLASH.d ./source/FLASH.o ./source/GPIO.d ./source/GPIO.o ./source/NVHoang12.d ./source/NVHoang12.o ./source/SREC.d ./source/SREC.o ./source/UART.d ./source/UART.o

.PHONY: clean-source

