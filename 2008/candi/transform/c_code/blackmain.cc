#include "screenio.h"
#include "imageutils.h"
#include "texcode.h"
#include "getwhim.h"
#include "getorim.h"
#include "curtain.h"
#include <stdio.h>
#include <stdlib.h>
extern "C" {
#include "utilfuncs.h"
}

static Image * infr1=new Image;
static Buffer2D<PixelRGB> fr1,whim,orim,barim;



extern "C" void blackmain() {
	
	/* get image */
	ImageLoad ("1.bmp", infr1);
	fr1.copyFrom (infr1->width,infr1->height, (PixelRGB*) infr1->data);
	free (infr1->data);					//don't leak memory!

	/* process */
	orim = getorim (fr1);
	whim = getwhim (fr1);
	barim = curtain (whim, orim);
	

	/* put image into screen */
	screen = &barim;
	/* put screen into graphics card*/
	NextFrame();
	
}
