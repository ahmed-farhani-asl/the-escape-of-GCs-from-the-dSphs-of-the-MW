
#include "escRate.h"

void RK10th(){

	double dx[2], dy[2], dz[2], dvx[2], dvy[2], dvz[2],
	       tempx0, tempy0, tempz0;	
	
	dx[0]=0; dy[0]=0; dz[0]=0;
	dvx[0]=0; dvy[0]=0; dvz[0]=0;

	dx[1]=0; dy[1]=0; dz[1]=0;
	dvx[1]=0; dvy[1]=0; dvz[1]=0;	

	tempz0 = mrv[0][3];
	tempy0 = mrv[0][2];
	tempx0 = mrv[0][1];
	
	for(int s=0; s<17; s++){

		temp1[1][s] = 0;
		temp2[1][s] = 0;
		temp3[1][s] = 0;
	}

	for(stage=0; stage<17; stage++){
		
		temp1[0][stage] = 0;
		temp2[0][stage] = 0;
		temp3[0][stage] = 0;
		
		temp1[1][stage] = 0;
		temp2[1][stage] = 0;
		temp3[1][stage] = 0;
		
		acc(0);

		for(int i=0; i<stage; i++){

			temp1[0][stage] += a[stage][i]*fx;
   			temp2[0][stage] += a[stage][i]*fy;
			temp3[0][stage] += a[stage][i]*fz;
		}

		temp1[0][stage] *= dt*dt;
		temp2[0][stage] *= dt*dt;
		temp3[0][stage] *= dt*dt;
			
		acc(1);

		for(int i=0; i<stage; i++){

			temp1[1][stage] += a[stage][i]*fx;
   			temp2[1][stage] += a[stage][i]*fy;
			temp3[1][stage] += a[stage][i]*fz;
		}

		temp1[1][stage] *= dt*dt;
		temp2[1][stage] *= dt*dt;
		temp3[1][stage] *= dt*dt;
			
		acc(0);

		mrv[0][1] += c[stage]*(mrv[0][4] + fx*dt)*dt;
		mrv[0][2] += c[stage]*(mrv[0][5] + fy*dt)*dt;
		mrv[0][3] += c[stage]*(mrv[0][6] + fz*dt)*dt;

		dx[0] += mrv[0][1] - tempx0;
		dy[0] += mrv[0][2] - tempy0;
		dz[0] += mrv[0][3] - tempz0;

		dvx[0] += c[stage]*fx;
		dvy[0] += c[stage]*fy;
		dvz[0] += c[stage]*fz;
		
		acc(1);
		
		dx[1] += c[stage]*(mrv[1][4] + fx*dt);
		dy[1] += c[stage]*(mrv[1][5] + fy*dt);
		dz[1] += c[stage]*(mrv[1][6] + fz*dt);
			
		dvx[1] += c[stage]*fx;
		dvy[1] += c[stage]*fy;
		dvz[1] += c[stage]*fz;
			
		mrv[0][1] = tempx0;
		mrv[0][2] = tempy0;
		mrv[0][3] = tempz0;
	}
	
	dx[1] *= dt;
	dy[1] *= dt;
	dz[1] *= dt;

	dvx[0] *= dt;
	dvy[0] *= dt;
	dvz[0] *= dt;

	dvx[1] *= dt;
	dvy[1] *= dt;
	dvz[1] *= dt;
		
	for(int j=0; j<2; j++){
		
		mrv[j][4] += dvx[j];
		mrv[j][5] += dvy[j];
		mrv[j][6] += dvz[j];

		mrv[j][1] += dx[j];
		mrv[j][2] += dy[j];
		mrv[j][3] += dz[j];	
	}

	dis = sqrt(pow(mrv[0][1] - mrv[1][1], 2) + pow(mrv[0][2] - mrv[1][2], 2) + pow(mrv[0][3] - mrv[1][3], 2));
}

