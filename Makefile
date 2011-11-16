all:
	$(MAKE) -C ./Muphic/abcmidi
	$(MAKE) -C ./Muphic/muphic-codeblocks
	$(MAKE) -C ./Muphic/Phic/phic-codeblocks
	$(MAKE) -C ./Muphic/Mu/mu-codeblocks
	$(MAKE) -C ./GUI/GUIQt
