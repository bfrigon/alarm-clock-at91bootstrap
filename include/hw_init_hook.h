#ifndef __HW_INIT_HOOK_H__
#define __HW_INIT_HOOK_H__


#define ADDR_PCA9634_SWRESET    0x03

#define ADDR_PCA9634_ALLCALL    0x70
#define ADDR_PCA9634_DIGIT_1    0x68
#define ADDR_PCA9634_DIGIT_2    0x69
#define ADDR_PCA9634_DIGIT_3    0x6a
#define ADDR_PCA9634_DIGIT_4    0x6b
#define ADDR_PCA9634_BASE       0x51
 
 
#define PCA9634_REG_MODE_1      0x00
#define PCA9634_REG_MODE_2      0x01
#define PCA9634_REG_PWM0        0x02
#define PCA9634_REG_PWM1        0x03
#define PCA9634_REG_PWM2        0x04
#define PCA9634_REG_PWM3        0x05
#define PCA9634_REG_PWM4        0x06
#define PCA9634_REG_PWM5        0x07
#define PCA9634_REG_PWM6        0x08
#define PCA9634_REG_PWM7        0x09
#define PCA9634_REG_GRPPWM      0x0A
#define PCA9634_REG_GRPFREQ     0x0B
#define PCA9634_REG_LEDOUT0     0x0C
#define PCA9634_REG_LEDOUT1     0x0D
 
#define PCA9634_AUTO_INCREMENT  0x80 
 
 
 
int pca9634_write_table(unsigned char dev_addr, unsigned char *data, unsigned int lenght);

#endif /* #ifndef __HW_INIT_HOOK_H__ */