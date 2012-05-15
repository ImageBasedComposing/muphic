all:
	sudo $(SHELL) makeall3makes.sh
	qmake -config release -o ./GUI/GUIQt/Makefile ./GUI/GUIQt/GUIQt.pro
	$(MAKE) -C ./Muphic/abcmidi
	$(MAKE) -C ./Muphic/muphic-codeblocks
	$(MAKE) -C ./Muphic/Phic/phic-codeblocks
	$(MAKE) -C ./Muphic/Mu/mu-codeblocks
	$(MAKE) -C ./GUI/GUIQt
	mv ./GUI/GUIQt/GUIQt ./Muphic/bin/Debug/GUIQt_linux
	sudo $(MAKE) -C ./Muphic/timidity
	sudo mv ./Muphic/timidity/timidity/timidity ./Muphic/bin/Debug/

clean:

	$(MAKE) clean -iC ./Muphic/abcmidi
	$(MAKE) clean -iC ./Muphic/muphic-codeblocks
	$(MAKE) clean -iC ./Muphic/Phic/phic-codeblocks
	$(MAKE) clean -iC ./Muphic/Mu/mu-codeblocks
	$(MAKE) clean -iC ./GUI/GUIQt	
	$(MAKE) clean -iC ./Muphic/timidity


