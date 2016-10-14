/**
 * \file
 * \brief Timer driver
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for all our timers.
  */

#include "Platform.h"
#if PL_CONFIG_HAS_TIMER
#include "Timer.h"
#if PL_CONFIG_HAS_EVENTS
  #include "Event.h"
#endif
#if PL_CONFIG_HAS_TRIGGER
  #include "Trigger.h"
#endif
#if PL_CONFIG_HAS_MOTOR_TACHO
  #include "Tacho.h"
#endif

static uint16 cnt;

void TMR_OnInterrupt(void) {

	if(cnt <= 100){
		cnt++;
	}else{
		EVNT_SetEvent(EVNT_LED_HEARTBEAT);
		cnt = 0;
	}
}

void TMR_Init(void) {

}

void TMR_Deinit(void) {
}

#endif /* PL_CONFIG_HAS_TIMER*/
