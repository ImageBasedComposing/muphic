all:
	qmake -config release -o ./GUI/GUIQt/Makefile ./GUI/GUIQt/GUIQt.pro
	$(MAKE) -C ./Muphic/abcmidi
	$(MAKE) -C ./Muphic/muphic-codeblocks
	$(MAKE) -C ./Muphic/Phic/phic-codeblocks
	$(MAKE) -C ./Muphic/Mu/mu-codeblocks
	$(MAKE) -C ./GUI/GUIQt
	mv ./GUI/GUIQt/GUIQt ./Muphic/bin/Debug/GUIQt_linux


