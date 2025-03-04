
#include "escRate.h"

double tf(double r){

	double const 
			alpha = 24.442303306535322;

	double 
		rt = pow(g*0.1/(2*pow(alpha, 2)), 1.0/3.0)*pow(r*(pow(8.3/r, 2) + 1.0), 2.0/3.0);
	
	return rt;
}
