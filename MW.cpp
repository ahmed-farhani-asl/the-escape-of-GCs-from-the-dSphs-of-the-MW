
#include "escRate.h"

void MW(int j){

	double const 
			alpha = 571.2099999999999,
			beta = 68.89000000000001,
		     	
			md = 50,
			mb = 15,
			
			a = 4,
			b = 0.5,
			
			a1 = g*mb,
			a2 = g*md;
	
	fx = -alpha*(mrv[j][1] + temp1[j][stage])/(beta + pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(mrv[j][3] + temp3[j][stage], 2))
		-a2*(mrv[j][1] + temp1[j][stage])/pow(pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(a + sqrt(b*b + pow(mrv[j][3] + temp3[j][stage], 2)), 2), 1.5)
		-a1*(mrv[j][1] + temp1[j][stage])/pow(pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(mrv[j][3] + temp3[j][stage], 2), 1.5);
	
	fy = -alpha*(mrv[j][2] + temp2[j][stage])/(beta + pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(mrv[j][3] + temp3[j][stage], 2))
                -a2*(mrv[j][2] + temp2[j][stage])/pow(pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(a + sqrt(b*b + pow(mrv[j][3] + temp3[j][stage], 2)), 2), 1.5)
		-a1*(mrv[j][2] + temp2[j][stage])/pow(pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(mrv[j][3] + temp3[j][stage], 2), 1.5);
	
	fz = -alpha*(mrv[j][3] + temp3[j][stage])/(beta + pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(mrv[j][3] + temp3[j][stage], 2))
		-a1*(mrv[j][3] + temp3[j][stage])/pow(pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(mrv[j][3] + temp3[j][stage], 2), 1.5)
		-a2*(mrv[j][3] + temp3[j][stage])*(a + sqrt(b*b + pow(mrv[j][3] + temp3[j][stage], 2)))/(sqrt(b*b + pow(mrv[j][3] + temp3[j][stage], 2))*pow(pow(mrv[j][1] + temp1[j][stage], 2) + pow(mrv[j][2] + temp2[j][stage], 2) + pow(a + sqrt(b*b + pow(mrv[j][3] + temp3[j][stage], 2)), 2), 1.5));
}

