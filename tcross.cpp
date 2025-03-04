
#include "escRate.h"

double tcross(double r){

	double 
		T = 2*pi*pow(r, 1.5)/sqrt(g*mdg(r));

	return T;
}
