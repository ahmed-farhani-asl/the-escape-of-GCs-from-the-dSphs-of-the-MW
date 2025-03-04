
#include "escRate.h"

double maxwell_rand(double exterm){

	double 
		r, x1, x2, f1, f2;

	x1 = 4*exterm*((double) rand() / RAND_MAX);
	f1 = maxwell(x1, exterm)*((double) rand() / RAND_MAX);

	x2 = 4*exterm*((double) rand() / RAND_MAX); 
	f2 = maxwell(x2, exterm)*((double) rand() / RAND_MAX);

	if(f2>f1) r = x2;
	if(f2<f1) r = x1;

	return r;
}
