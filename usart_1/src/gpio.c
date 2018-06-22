
#include "project.h"

void pin_init(void)
{
    unsigned int tempreg;

    /* set mode led ld3 */
    tempreg = read_reg(GPIOC_MODER, ~(0x03 << 18));
    tempreg |= (GPIO_MODER_OUTPUT << 18);
    write_reg(GPIOC_MODER, tempreg);


    /* set mode led ld4 */
    tempreg = read_reg(GPIOC_MODER, ~(0x03 << 16));
    tempreg |= (GPIO_MODER_OUTPUT << 16);
    write_reg(GPIOC_MODER, tempreg);


    /* set mode user button */
    tempreg = read_reg(GPIOA_MODER, ~(0x03 << 0));
    tempreg |= (GPIO_MODER_INPUT << 0);
    write_reg(GPIOA_MODER, tempreg);


    /* set mode PA2 */
    tempreg = read_reg(GPIOA_MODER, ~(0x03 << 4));
    tempreg |= (GPIO_MODER_INPUT << 4);
    write_reg(GPIOA_MODER, tempreg);
    /* pull up */
    tempreg = read_reg(GPIOA_PUPDR, ~(0x03 << 4));
    tempreg |= (0x01 << 4);
    write_reg(GPIOA_PUPDR, tempreg);


    /* PA10 - Rx */
	#if 1
    tempreg = read_reg(GPIOA_MODER, ~(0x03 << 20));
    tempreg |= (GPIO_MODER_ALT << 20);
    write_reg(GPIOA_MODER, tempreg);
	
	/* pull down */
    tempreg = read_reg(GPIOA_PUPDR, ~(0x03 << 20));
    tempreg |= (0x01 << 20);
    write_reg(GPIOA_PUPDR, tempreg);

	/* alt */
    tempreg = read_reg(GPIOA_AFRH, ~(0xF << 8));
    tempreg |= (AF1 << 8);
    write_reg(GPIOA_AFRH, tempreg);
	#else
    tempreg = read_reg(GPIOB_MODER, ~(0x03 << 20));
    tempreg |= (GPIO_MODER_ALT << 20);
    write_reg(GPIOB_MODER, tempreg);
	
	/* pull down */
    tempreg = read_reg(GPIOB_PUPDR, ~(0x03 << 20));
    tempreg |= (0x02 << 20);
    write_reg(GPIOB_PUPDR, tempreg);

    tempreg = read_reg(GPIOB_AFRL, ~(0xF << 8));
    tempreg |= (AF0 << 8);
    write_reg(GPIOB_AFRL, tempreg);
	#endif

    /* PA9 - Tx */
	#if 1
    tempreg = read_reg(GPIOA_MODER, ~(0x03 << 18));
    tempreg |= (GPIO_MODER_ALT << 18);
    write_reg(GPIOA_MODER, tempreg);
	
	/* pull up */
    tempreg = read_reg(GPIOA_PUPDR, ~(0x03 << 18));
    tempreg |= (0x01 << 18);
    write_reg(GPIOA_PUPDR, tempreg);

    tempreg = read_reg(GPIOA_AFRH, ~(0xF << 4));
    tempreg |= (AF1 << 4);
    write_reg(GPIOA_AFRH, tempreg);
	#else
	/* PB6 */
    tempreg = read_reg(GPIOB_MODER, ~(0x03 << 12));
    tempreg |= (GPIO_MODER_ALT << 12);
    write_reg(GPIOB_MODER, tempreg);
	
	/* pull down */
    tempreg = read_reg(GPIOB_PUPDR, ~(0x03 << 12));
    tempreg |= (0x02 << 12);
    write_reg(GPIOB_PUPDR, tempreg);

    tempreg = read_reg(GPIOB_AFRL, ~(0xF << 24));
    tempreg |= (AF0 << 24);
    write_reg(GPIOB_AFRL, tempreg);
		
	#endif
}

void led_on(unsigned char pin_number)
{
    write_reg(GPIOC_BSRR, 1u << pin_number);
}

void led_off(unsigned char pin_number)
{
    write_reg(GPIOC_BSRR, 1u << (pin_number + 16u));
}

