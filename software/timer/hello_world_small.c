#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"

#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"

#include "system.h"

static unsigned counter = 0;
static unsigned PORT_7_SEGMENT='7b1111111';

static void timer_isr(void *context)
{
	(void) context;

	//counter = counter << 1 |(IORD_ALTERA_AVALON_PIO_DATA(PIO_SWITCH_0_BASE) & 1);
	//IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, leds);

	//IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);

	if (IORD_ALTERA_AVALON_PIO_DATA(PIO_SWITCH_0_BASE) & 1)
	{
		counter = counter + 1;

		if(counter < 60)
		{
			switch(counter)
			{
				case 0:
					PORT_7_SEGMENT='7b10001000';
					IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					break;

				 case 1:
					 PORT_7_SEGMENT='7b10111110';
					IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;

				 case 2:
					 PORT_7_SEGMENT='7b00011001';
					IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;

				 case 3:
					 PORT_7_SEGMENT='7b00011100';
					 IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;

				 case 4:
					 PORT_7_SEGMENT='7b00101110';
					 IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;

				 case 5:
					 PORT_7_SEGMENT='7b01001100';
					 IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;

				 case 6:
					 PORT_7_SEGMENT='7b01001000';
					 IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;

				 case 7:
					 PORT_7_SEGMENT='7b10111100';
					 IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;

				 case 8:
					 PORT_7_SEGMENT='7b00001000';
					 IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;

				 case 9:
					 PORT_7_SEGMENT='7b00001100';
					 IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, PORT_7_SEGMENT);
					 break;
			}
		}
	}

	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
}

int main()
{
	alt_ic_isr_register(
			TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,
			TIMER_0_IRQ,
			timer_isr,
			NULL,
			NULL);

	IOWR_ALTERA_AVALON_TIMER_CONTROL(
			TIMER_0_BASE,
			ALTERA_AVALON_TIMER_CONTROL_ITO_MSK
			| ALTERA_AVALON_TIMER_CONTROL_CONT_MSK);

  /* Event loop never exits. */
  while (1);

  return 0;
}



//#include "sys/alt_stdio.h"
//
//int main()
//{
//  alt_putstr("Hello from Nios II!\n");
//
//  while (1);
//
//  return 0;
//}
