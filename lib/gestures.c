#include "gestures.h"

void GESTURES_Init() {
	SystemInit();
	TM_DELAY_Init();
	TM_DISCO_LedInit();
	
	if (TM_LIS302DL_LIS3DSH_Detect() == TM_LIS302DL_LIS3DSH_Device_LIS302DL) {
	TM_DISCO_LedOn(LED_GREEN | LED_RED);
	TM_LIS302DL_LIS3DSH_Init(TM_LIS302DL_Sensitivity_2_3G, TM_LIS302DL_Filter_2Hz);
	} else if (TM_LIS302DL_LIS3DSH_Detect() == TM_LIS302DL_LIS3DSH_Device_LIS3DSH) {
	TM_DISCO_LedOn(LED_BLUE | LED_ORANGE);
	TM_LIS302DL_LIS3DSH_Init(TM_LIS3DSH_Sensitivity_2G, TM_LIS3DSH_Filter_800Hz);
	} else {
		TM_DISCO_LedOn(LED_GREEN | LED_RED | LED_BLUE | LED_ORANGE);
		while (1);
	}
	if(DEBUG) Delayms(2000);
	return;
}

/*
GESTURES_t GESTURES_GetGesture() {
	return 0;
}
*/

