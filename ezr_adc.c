#include "em_device.h"
#include "em_chip.h"
#include "em_adc.h"
#include "em_cmu.h"
int main(void)
{
	uint32_t data =0;
  /* Chip errata */
  CHIP_Init();

  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
 CMU_ClockEnable(cmuClock_ADC0, true);

 ADC0->CTRL = 0x001F0000;
 ADC0->SINGLECTRL = 0x00010B00;
 ADC0->CAL = 0x3F007F00;
 ADC0->BIASPROG = 0x00000747;

  /* Infinite loop */
  while (1) {

	  ADC0->CMD = ADC_CMD_SINGLESTART;
	//while(!(ADC0->IF = ADC_IF_SINGLE));

		data = ADC0->SINGLEDATA;
  }
}
