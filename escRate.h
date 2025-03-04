#ifndef ESCRATE_H
#define ESCRATE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

double const 

	G = 6.67408*pow(10, -11),								// gravitational constant SI units m^3 kg^-1 s -2

	au = 1.495978707*pow(10, 11),								// astrophysical unit per meter

	pc = 3.08567758*pow(10, 16),								// parsec per meter

	sm = 1.98847*pow(10, 30),								// solar mass per kg

	yr = 3.15576*pow(10, 7),								// year per second

	pi = 3.14159265, 									// pi constant number value

	e = 2.71828182, 									// neper constant number value

	kilo = pow(10, 3),									// one kilo value

	mega = pow(10, 6),									// one mega value

	giga = pow(10, 9),									// one giga value

	dt = 0.001,										// time_step; is used in runge_kutta() iteration method

	g = G*(giga*sm)*pow(100*mega*yr, 2)/pow(kilo*pc, 3);					// G constant in arbitrary units

int const

	tcrit = 138.0/dt,									// simulation time ( x100 Myr )

      	repeat = 100;										// redefine percentage^-1

extern int
	t,                                                                                      // counter for time
	
	k,											// counter to repeat trial

	esc,											// counter for escapers number

	layer,											// counter for layers of dg

	pass,											// password to pass through conditions in checkcl()

	stage;											// RK10th stage

extern double 

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
	
extern ofstream

	*w;
		
extern bool

	accept;	

void define();											// to define arrays

void inidg();											// to initialize dg

void RK10th();											// to apply runge_kutta method (10th order)

void acc(int);											// to determine resultant acceleration

void MW(int);											// to determine acceleration due to Milky-Way potential (H.Haghi 2015)

void write();											// to write position data to file; modifiable 

void plot();											// to plot positions (default); modifiable

double tf(double);										// to determine tidal field; returns tidal radius

double escV(double);										// to determine escape velocity from dg

double mdg(double);										// to determine effective dg mass

double iniV(double, double);									// to determine an orbit around MW; returns corespondent initial velocity

double tcross(double);										// to determine crossing time of dg

double maxwell_rand(double);									// to generate random numbers with Maxwelian distribution

double maxwell(double, double);									// Maxwell-Boltzmann distribution with specific extremum and v; returns f(v)dv

#endif
