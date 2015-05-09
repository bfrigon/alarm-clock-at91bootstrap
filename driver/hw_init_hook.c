#include "common.h"
#include "hardware.h"
#include "twi.h"
#include "debug.h"

#include "hw_init_hook.h"


void hw_init_hook(void)
{
    
    unsigned char init_digit_1[14] = { 0x81, 0x15, 0x60, 0x60, 0x60, 
                                       0x60, 0x60, 0x60, 0x60, 0x60, 
                                       0xFF, 0x00, 0x00, 0xC0};
    
    unsigned char init_digit_2[14] = { 0x81, 0x15, 0x60, 0x60, 0x60, 
                                       0x60, 0x60, 0x60, 0x60, 0x60, 
                                       0xFF, 0x00, 0x00, 0xC0 };
    
    unsigned char init_digit_3[14] = { 0x81, 0x15, 0x60, 0x60, 0x60, 
                                       0x60, 0x60, 0x60, 0x60, 0x60, 
                                       0xFF, 0x00, 0x00, 0xC0 };
    
    unsigned char init_digit_4[14] = { 0x81, 0x15, 0x60, 0x60, 0x60, 
                                       0x60, 0x60, 0x60, 0x60, 0x60, 
                                       0xFF, 0x00, 0x00, 0xC0 };

    unsigned char init_base[14] = { 0x81, 0x25, 0x60, 0x60, 0x60, 
                                   0x60, 0x60, 0x60, 0x60, 0x60, 
                                   0x80, 0x23, 0x00, 0x03 };                                       
                                       
    
    pca9634_write_table(ADDR_PCA9634_DIGIT_1, init_digit_1, 14);
    pca9634_write_table(ADDR_PCA9634_DIGIT_2, init_digit_2, 14);
    pca9634_write_table(ADDR_PCA9634_DIGIT_3, init_digit_3, 14);
    pca9634_write_table(ADDR_PCA9634_DIGIT_4, init_digit_4, 14);
    pca9634_write_table(ADDR_PCA9634_BASE, init_base, 14);
}

int pca9634_write_table(unsigned char dev_addr, unsigned char *data, unsigned int length)
{
    int ret;

    ret = twi_write(dev_addr, 
                    PCA9634_REG_MODE_1 | PCA9634_AUTO_INCREMENT, 
                    1, data, length);
    
    if (ret) {
        dbg_loud("TWI: Failed to write to device at %x\r\n", dev_addr);
        return -1;
    }
    
    return 0;
}


