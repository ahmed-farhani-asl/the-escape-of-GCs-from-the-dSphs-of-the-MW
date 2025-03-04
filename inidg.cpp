
#include "escRate.h"

void inidg(){

	mrv[0][1] = xdg;
	mrv[0][2] = 0.0;
	mrv[0][3] = 0.0;
	
	mrv[0][4] = 0.0;
	mrv[0][5] = iniV(xdg, ecc);
 	mrv[0][6] = 0.0;

	esc = 0;
	escRate = 0;
	rdg = 0;

	tr = tf(xdg);
}
