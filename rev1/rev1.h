#pragma once

#include "helldiver.h"

#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
#include "ws2812.h"
#endif

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
	L00, L01, L02, \
	L10, L11, L12, \
	L20, L21, L22 \
	) \
	{ \
		{ L00, L01, L02 }, \
		{ L10, L11, L12 }, \
		{ L20, L21, L22 }, \
	}
