/* Include core modules */
#include "stm32f4xx.h"

#include "gestures.h"

/* The main function is called from the startup code in file
 * Libraries/CMSIS/ST/STM32F4xx/Source/Templates/TrueSTUDIO/startup_stm32f4xx.s
 * (line 101)
 */
int main(void)
{
	GESTURES_Init();	

	while (1) {
		
		/* Get current gesture */
		GESTURE_t gesture = GESTURES_GetGesture();
		
		/* Light correct LED */
		switch (gesture) {

			case RIGHT: 
				TM_DISCO_LedOn(LED_GREEN);
				TM_DISCO_LedOff(LED_RED | LED_BLUE | LED_ORANGE);
				break;
		
			case LEFT:			
				TM_DISCO_LedOn(LED_RED);
				TM_DISCO_LedOff(LED_GREEN | LED_BLUE | LED_ORANGE);
				break;
		
			case FORWARD:
				TM_DISCO_LedOn(LED_BLUE);
				TM_DISCO_LedOff(LED_GREEN | LED_RED | LED_ORANGE);
				break;
			
			case BACK:	
				TM_DISCO_LedOn(LED_ORANGE);
				TM_DISCO_LedOff(LED_GREEN | LED_RED | LED_BLUE);
				break;
		
			case BAD:
				TM_DISCO_LedOn(LED_GREEN | LED_RED | LED_ORANGE | LED_BLUE);	
				break;

		}
	}       
}
