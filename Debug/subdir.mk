################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Enemy.cpp \
../Game.cpp \
../InterfaceDisplay.cpp \
../Menu.cpp \
../Player.cpp \
../Projectile.cpp \
../Weapon.cpp \
../main.cpp 

OBJS += \
./Enemy.o \
./Game.o \
./InterfaceDisplay.o \
./Menu.o \
./Player.o \
./Projectile.o \
./Weapon.o \
./main.o 

CPP_DEPS += \
./Enemy.d \
./Game.d \
./InterfaceDisplay.d \
./Menu.d \
./Player.d \
./Projectile.d \
./Weapon.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


