################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Enemy.cpp \
../Game.cpp \
../Menu.cpp \
../Player.cpp \
../Projectile.cpp \
../main.cpp 

OBJS += \
./Enemy.o \
./Game.o \
./Menu.o \
./Player.o \
./Projectile.o \
./main.o 

CPP_DEPS += \
./Enemy.d \
./Game.d \
./Menu.d \
./Player.d \
./Projectile.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


