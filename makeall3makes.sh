#!/bin/bash

./cbp2make-linux-bin -in './Muphic/muphic-codeblocks/Muphic.cbp' -out ./Muphic/muphic-codeblocks/Makefile

./cbp2make-linux-bin -in './Muphic/Phic/phic-codeblocks/Phic.cbp' -out ./Muphic/Phic/phic-codeblocks/Makefile

./cbp2make-linux-bin -in './Muphic/Mu/mu-codeblocks/Mu.cbp' -out ./Muphic/Mu/mu-codeblocks/Makefile


exit 0
