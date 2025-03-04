
#include "escRate.h"

int
	t,                                                                                      // counter for time
	
	k,											// counter to repeat trial

	esc,											// counter for escapers number

	layer,											// counter for layers of dg

	pass,											// password to pass through conditions in checkcl()

	stage;											// RK10th stage

double 

	mrv[2][7], 											// 2D array contains mass+coordinates+velocities values of all objects

	fx, 											// acceleration x direction

	fy, 											// acceleration y direction

	fz,											// acceleration z direction used in acc()

	**temp1,						 				// 1st temporary quantity

	**temp2,										// 2nd temporary quantity

	**temp3,										// 3rd temporary quantety used in runge_kutta() algorythm steps

	**a,											// a coefficients of RK10th

	*b,											// b coefficients of RK10th

	*c,											// c coefficients of RK10th

	xdg,											// dg-MW initial distance

	ecc, 											// eccentricity of dg orbit

	escRate, 										// escape rate of cls from dgs

	rdg, 											// radius of dg in current layer

	drdg,											// current layer width of dg

	beta,											// cl is checked at beta*T in checkcl()

	subl,											// number of sublayers of dg

	theta,											// theta in spherical coordinates

	phi,											// phi in spherical coordinates; are used for initial position and velocity direction of cl

	randrcl,										// random initial for dis

	randvcl,										// random initial for velocity for cl relative to dg

	escterm,										// escape condition; is compared with dis

	dis,											// dg-cl distance

	tr,											// tidal radius

	T;											// crossing time of dg; is used as orbit period
	
ofstream *w;

bool accept=true;

void define(){

	ifstream r("RK10th.txt");
	
	w = new ofstream [6];
	
	temp1 = new double *[2];
	temp2 = new double *[2];
	temp3 = new double *[2];

	for(int i=0; i<2; i++){
	
		temp1[i] = new double [17];
		temp2[i] = new double [17];
		temp3[i] = new double [17];
	}

	a = new double *[17];

	a[0] = new double [1];
	a[1] = new double [1];

	for(int i=2; i<17; i++)

		a[i] = new double [i-1];

	b = new double [17];
	c = new double [17];

	for(int i=0; i<17; i++)
		r>>b[i];

	for(int i=0; i<17; i++)
	        r>>c[i];

	a[0][0] = 0;
	r>>a[1][0];

	for(int i=2; i<17; i++)
		for(int j=0; j<i; j++)
			r>>a[i][j];
}

