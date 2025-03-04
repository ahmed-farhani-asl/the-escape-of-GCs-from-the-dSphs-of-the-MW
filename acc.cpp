
#include "escRate.h"

void acc(int j){
	
        fx = 0; fy = 0; fz = 0;

	MW(j);
	
	if(j==1){
	
		dis = sqrt(pow(mrv[0][1] - mrv[1][1] + temp1[0][stage] - temp1[1][stage], 2) + pow(mrv[0][2] - mrv[1][2] + temp2[0][stage] - temp2[1][stage], 2) + pow(mrv[0][3] - mrv[1][3] + temp3[0][stage] - temp3[1][stage], 2));

		mrv[0][0] = mdg(dis);

        	fx += g*mrv[0][0]*(mrv[0][1] - mrv[1][1] + temp1[0][stage] - temp1[1][stage])/pow(dis, 3);

		fy += g*mrv[0][0]*(mrv[0][2] - mrv[1][2] + temp2[0][stage] - temp2[1][stage])/pow(dis, 3);	                
			
		fz += g*mrv[0][0]*(mrv[0][3] - mrv[1][3] + temp3[0][stage] - temp3[1][stage])/pow(dis, 3);	                
	}
}

