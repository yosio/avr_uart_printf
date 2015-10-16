/*
-----
2015/10/16
powerd by Yasuhiro
*/
#include <avr/io.h>
#include <stdio.h>
#include "CUart.h"

static int uartPutchar(char c, FILE *stream);

void
CUart::initForPrintf(uint32_t baud)
{
    fdevopen(uartPutchar, NULL);   //stdoutにuartPutcharを設定

    uint16_t ubrr = F_CPU / 16 / baud - 1;
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0C = (1<<UCSZ00)|(1<<UCSZ01); //フレーム形式(8ビット、ストップビット1、パリティなし)
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);   //送受信許可
}

static int
uartPutchar(char c, FILE *stream)
{
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    return 0;
}
