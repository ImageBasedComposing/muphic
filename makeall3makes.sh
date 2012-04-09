#!/bin/bash


cd ./Resources/cbp2make
make
cd ./../..
./Resources/cbp2make/bin/Release/cbp2make -in './Muphic/muphic-codeblocks/Muphic.cbp' -out ./Muphic/muphic-codeblocks/Makefile
./Resources/cbp2make/bin/Release/cbp2make -in './Muphic/Phic/phic-codeblocks/Phic.cbp' -out ./Muphic/Phic/phic-codeblocks/Makefile
./Resources/cbp2make/bin/Release/cbp2make -in './Muphic/Mu/mu-codeblocks/Mu.cbp' -out ./Muphic/Mu/mu-codeblocks/Makefile
cd ./Muphic/timidity
./configure
cd ./../..

exit 0
