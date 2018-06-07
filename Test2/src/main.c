#include "hw_stm32f030_mini.h"
#include <stdio.h>

float Sum(int a)
{
	int i = 0;
	float sum = 0;
//	float m = 0;
	for (i=1; i <= a; i++)
	{
//		m = 1.0*(1/(1.0*i));
//		sum = sum + i;
	}
	return (sum);
}
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
  /* int clock */
  enabled_clk();
  /* init red led */
  init_led_pin();
  Sum(100);
  while(1)
  {
    led_on();
    delay(0xff);
    led_off();
    delay(0xff);
  }
}
void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}
