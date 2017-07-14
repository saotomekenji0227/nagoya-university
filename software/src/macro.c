#include <stdio.h>
#include "txtfmt.h"

void macro(){

  puts("%!PS-Adobe-1.0\n%%Pages: (atend)\n%%BoundingBox: (atend)\n%%EndComments\n\n%\n% $Id: prologue.ps,v 1.7 1994/04/10 08:33:40 yamamoto Exp yamamoto $\n%\n\n% General macros.\n/curx {currentpoint pop} def\n/cury {currentpoint exch pop} def\n\n% Constans.		% Japanese character scale factor.\n/jscale 0.94 def\n\n% Commands.\n/n {			% - n -\n	sx cury dy sub moveto\n} def\n\n/f {			% - f -\n	showpage\n} def\n\n	/s {			% string font s -\n	dup K eq\n	{js}\n	{setfont show}\n	ifelse\n} def\n\n/js {			% string font js -\n	setfont\n	dw 0 rmoveto\n	dw 2 mul exch 0 exch ashow\n	dw neg 0 rmoveto\n} def\n\n% Initialization.\n/init {			% sx sy pt dy init -\n	gsave\n\n	/dy exch def\n	/pt exch def\n	/sy exch def\n	/sx exch def\n\n	fonts {\n		findfont pt scalefont def\n	} forall\n	jfonts {\n		findfont pt jscale mul scalefont def\n	} forall\n\n	% Dummy.\n	0 0 moveto\n\n	% Set character width.\n	C setfont\n	/asciiwidth (AA) stringwidth pop def\n	K setfont\n	/japanesewidth <2422> stringwidth pop def\n	/dw asciiwidth japanesewidth sub 2 div def\n\n	grestore\n} def\n\n% Default fonts.\n/fonts 3 dict def\nfonts begin\n	/B /Courier-Bold def			% Bold\n	/C /Courier def					% Courier\nend\n/jfonts 3 dict def\njfonts begin\n	/K /Ryumin-Light-EUC-H def		% Kanji (Mincho-tai)\nend\n\n25 768 10 12 init\n/b {sx sy moveto} def\n%%EndProlog");

}
