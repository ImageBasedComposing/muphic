TeX=latex
DVIPS=dvips
DVIPDF=dvipdfm
DVI=main.dvi
PDF=main.pdf
TEXMAIN=main.tex
TEXFILES=$(TEXMAIN)

pdf: toc.stamp $(DVI)
	$(DVIPDF) $(DVI)

ps: $(DVI)
	$(DVIPS) $(DVI)

toc.stamp:
	$(TeX) $(TEXMAIN)
	rm $(DVI)
	touch toc.stamp

$(DVI): $(TEXFILES)
	$(TeX) $(TEXMAIN)

clean:
	rm -f *.log *.dvi *.aux *.toc *.lof *.lot *.out *.pdf toc.stamp
