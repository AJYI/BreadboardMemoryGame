/**
 * avr.c
 * Copyright (C) 2001-2020, Tony Givargis
 */

#include "avr.h"

void avr_wait(unsigned short msec)
{
    TCCR0 = 3;
    while (msec--)
    {
        TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001);
        SET_BIT(TIFR, TOV0);
        while (!GET_BIT(TIFR, TOV0))
            ;
    }
    TCCR0 = 0;
}

void avr_wait_original(unsigned short msec)
{
    TCCR0 = 3;
    while (msec--)
    {
        TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001);
        SET_BIT(TIFR, TOV0);
        while (!GET_BIT(TIFR, TOV0))
            ;
    }
    TCCR0 = 0;
}