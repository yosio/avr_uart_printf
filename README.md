# avr_uart_printf

##ビルド方法
make

##書き込み方法
hidspx main.ihex

##参考サイト

LinuxでのAVR開発環境構築方法
http://d.hatena.ne.jp/over80/20100506/avr_build

UARTでprintf
http://cega.jp/avr-libc-jp/group__avr__stdio.html

軽量printf(えるむ)
http://elm-chan.org/fsw/strf/xprintf_j.html
 →軽量という触れ込みだが、avr-g++の場合stdio.hのprintf()を使用した場合とサイズに変化がなかった。(いづれも7kB程度)

Makefileの書き方
http://www.ie.u-ryukyu.ac.jp/~e085739/c.makefile.tuts.html
