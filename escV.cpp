
#include "escRate.h"

double escV(double r){

	double 
		vesc = sqrt(2*g*0.1/(r + 0.5));

	return vesc;
}
