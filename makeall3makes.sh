#!/bin/bash

mkdir Muphic/bin/Debug
cd 'Installation files - linux'
cp -R * ../Muphic/bin/Debug/
cd ..
sudo chmod -R 777 Muphic/bin/Debug/
cd ./Resources/cbp2make
make
cd ./../..
./Resources/cbp2make/bin/Release/cbp2make -in './Muphic/muphic-codeblocks/Muphic.cbp' -out ./Muphic/muphic-codeblocks/Makefile
./Resources/cbp2make/bin/Release/cbp2make -in './Muphic/Phic/phic-codeblocks/Phic.cbp' -out ./Muphic/Phic/phic-codeblocks/Makefile
./Resources/cbp2make/bin/Release/cbp2make -in './Muphic/Mu/mu-codeblocks/Mu.cbp' -out ./Muphic/Mu/mu-codeblocks/Makefile
cd ./Muphic/timidity
chmod +x ./configure
./configure --prefix=$(pwd)/../../Muphic/bin/Debug
cd ./../..
chmod +x ./Muphic/bin/Debug/launch.sh
ln ./Muphic/bin/Debug/launch.sh ./Muphic/bin/Debug/ExecMe

exit 0
