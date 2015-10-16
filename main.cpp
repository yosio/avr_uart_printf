#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "CUart.h"

int main(void)
{
    CUart::initForPrintf(38400ULL);

    uint8_t count = 0;
    for(;;count++){
        printf("%d\n", count);
        _delay_ms(500);
    }
}
