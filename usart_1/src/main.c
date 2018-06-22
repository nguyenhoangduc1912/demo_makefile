#include "project.h"


/*************************************************************************************************/

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void main(void)
{
    system_init();
    enabled_clock();
    pin_init();
    delay(0xff);
    usart_init();

    interrupt_init();
	
	/* usart_send_byte(0x55);
    delay(0xff); */

    /* send "Hello world -MCU" to terminal app on PC */
    usart_send_string("Hello world -MCU	\r\n");
    led_on(LD4_PIN);
    delay(0xff);
    led_off(LD4_PIN);
    delay(0xff);

    while(1)
    {
        if (0 != rx_data)
        {
            usart_send_byte(rx_data);
            rx_data = 0;
        }
    }
}

