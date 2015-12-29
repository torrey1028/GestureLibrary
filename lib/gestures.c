#include "gestures.h"

/* Private */
extern int abs(int);

/* Public */
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


GESTURE_t GESTURES_GetGesture() {

	TM_LIS302DL_LIS3DSH_t Axes_Data;

	/* Read axes data from initialized accelerometer */
	TM_LIS302DL_LIS3DSH_ReadAxes(&Axes_Data);

	int X = abs(Axes_Data.X);
	int Y = abs(Axes_Data.Y);
	int Z = abs(Axes_Data.Z);
	
	if (X > Y) {
		if (Axes_Data.X > 0)
			return FORWARD; 	
		else
			return BACK;
	} else {
		if (Axes_Data.Y > 0)
			return LEFT;
		else
			return RIGHT;
	}	
	
	return ERROR;
}

/* Private */
extern int abs(int num) {
	
	if (num < 0) num = num * -1;
	return num;

}

