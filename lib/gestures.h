/**
 * @author Becky Torrey
 * 
 * gestures.h
 * 
 * This library is a wrapper for gesture detection based on the STM34f
 * discovery board. I am using libraries from http://stm32f4-discovery.com
 */

#ifndef GESTURES_H
#define GESTURES_H

/* Core module */
#include "stm32f4xx.h"
/* Driver libraries */
#include "defines.h"
#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_lis302dl_lis3dsh.h"


typedef enum {
	RIGHT,
	LEFT,
	FORWARD,
	BACK,
	BAD	
} GESTURE_t;


/**
 * @brief	Runs accelerometer setup and LED setup
 * @param	None
 * @retval	None
 */
void GESTURES_Init(void);

/**
 * @brief	Queries accelerometer and returns current gesture
 * @param	None -- TODO: Add support for waiting for a gesture
 * @retval	GESTURE_t - current gesture
 */

GESTURE_t GESTURES_GetGesture(void);

#endif
