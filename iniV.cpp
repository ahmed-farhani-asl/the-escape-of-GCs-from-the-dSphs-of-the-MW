
#include "escRate.h"

double iniV(double apogee, double ec){
	
        double const

                gama1 = 671.8467685029376,
                gama2 = 2239.4892283431254,
                gama3 = 571.2099999999999,
                gama4 = 68.89000000000001;
		
	double
		
		rtemp = apogee/(1+ec),
		
		vtemp = sqrt(((1-ec)/(1+ec))*rtemp*(gama1*rtemp/pow(rtemp, 3)
                
			+ gama2*rtemp/pow(20.25 + rtemp*rtemp, 1.5)
                        
			+ gama3*rtemp/(gama4 + rtemp*rtemp)));

	return vtemp;
}
