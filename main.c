/* Include core modules */
#include "stm32f4xx.h"

#include "gestures.h"

/* The main function is called from the startup code in file
 * Libraries/CMSIS/ST/STM32F4xx/Source/Templates/TrueSTUDIO/startup_stm32f4xx.s
 * (line 101)
 */
int main(void)
{
	TM_LIS302DL_LIS3DSH_t Axes_Data;
	
	GESTURES_Init();	

	while (1) {
		/* Read axes data from initialized accelerometer */
		TM_LIS302DL_LIS3DSH_ReadAxes(&Axes_Data);

		/* Turn LEDS on or off */
		/* Check X axes */
		if (Axes_Data.X > 200) {
			TM_DISCO_LedOn(LED_RED);
		} else {
			TM_DISCO_LedOff(LED_RED);
		}
		if (Axes_Data.X <-200) {
			TM_DISCO_LedOn(LED_GREEN);
		} else {
			TM_DISCO_LedOff(LED_GREEN);
		}
		/* Check Y axes */
		if (Axes_Data.Y > 200) {
			TM_DISCO_LedOn(LED_ORANGE);
		} else {
			TM_DISCO_LedOff(LED_ORANGE);
		}
		if (Axes_Data.Y < -200) {
			TM_DISCO_LedOn(LED_BLUE);
		} else {
			TM_DISCO_LedOff(LED_BLUE);
		}
	}       
}
