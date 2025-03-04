
#include "escRate.h"

double maxwell(double x, double exterm){

	double
		maxwellian = 4.0*x*x/(sqrt(pi)*pow(exterm, 3)*pow(e, x*x/(exterm*exterm)));

	return maxwellian;
}
