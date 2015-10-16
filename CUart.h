/*
Target:ATMega88

UARTでprintfをするための初期設定を行う関数の提供

・使用できるボーレートはCPUのクロック数によって異なる(仕様書のボーレートの設定の項目参照)
・内部で周波数(F_CPU)を使用しているので適宜defineしてください
・最低限、GNDと、MCUのTXDピンとPC側のRXDピンを接続すればprintf()可能です

◆使用方法
initUartForPrintf(38400ULL);
printf("%d\n", 1);

-----
2015/10/16
powerd by Yasuhiro
*/
#ifndef CUART_H
#define CUART_H

class CUart
{
public:
    static void initForPrintf(uint32_t baud);
};

#endif