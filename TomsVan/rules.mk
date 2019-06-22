MCU = atmega32u4
F_CPU = 16000000
ARCH = AVR8
F_USB = 16000000
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
OPT_DEFS += -DBOOTLOADER_SIZE=4096
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
NKRO_ENABLE = yes
RGBLIGHT_ENABLE = yes
