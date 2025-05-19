TARGET = stm32c071_basic

# ابزارهای کامپایل
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size

# فلگ‌های کامپایلر
CFLAGS = -mcpu=cortex-m0 -mthumb -Wall -O2 -g -std=c11 -ffunction-sections -fdata-sections
LDFLAGS = -TSTM32C071C8TX_FLASH.ld -Wl,--gc-sections

# مسیرهای شامل هدرها (Include)
INCLUDES = \
  -ICore/Inc \
  -IDrivers/CMSIS/Device/ST/STM32C0xx/Include \
  -IDrivers/CMSIS/Include \
  -IDrivers/lowlevel \
  -IDrivers/lowlevel/GPIO \
  -IDrivers/lowlevel/USART \
  -IDrivers/lowlevel/SPI \
  -IDrivers/lowlevel/I2C

# فایل‌های سورس
SRC = \
  Core/Src/main.c \
  Core/Startup/startup_stm32c071c8tx.s \
  Drivers/lowlevel/GPIO/gpio.c \
  Drivers/lowlevel/USART/usart.c \
  Drivers/lowlevel/SPI/spi.c \
  Drivers/lowlevel/I2C/i2c.c \
  Drivers/lowlevel/Delay/delay.c

# تبدیل سورس‌ها به آبجکت
OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.s=.o)

# قانون پیش‌فرض
all: $(TARGET).elf

# لینک
$(TARGET).elf: $(OBJ)
 $(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)
 $(OBJCOPY) -O ihex $@ $(TARGET).hex
 $(OBJCOPY) -O binary $@ $(TARGET).bin
 $(SIZE) $@

# کامپایل فایل‌های .c
%.o: %.c
 $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# اسمبلی
%.o: %.s
 $(CC) $(CFLAGS) -c $< -o $@

# پاک‌سازی فایل‌های خروجی
clean:
 rm -f $(TARGET).elf $(TARGET).hex $(TARGET).bin $(OBJ)

.PHONY: all clean