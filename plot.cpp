
#include "escRate.h"
#include "gnuplot.h"

void plot(){
	
	Gnuplot gp;
	
	gp("set term x11");
 
	gp("set xlabel 'X(Kpc)'");
	gp("set ylabel 'Y(Kpc)'"); 
	gp("set zlabel 'Z(Kpc)'"); 

 	gp("sp 'cl.dat' u 2:3:4 w l title 'cluster', 'dg.dat' u 2:3:4 w l title 'DG'");
 
 	system("read -p 'Press Enter to continue...' var");

	gp("sp 'dg-cl.dat' u 2:3:4 w l title 'cluster-DG'");

	system("read -p 'Press Enter to continue...' var");
	
        gp("set xlabel 'time (100Myr)'");
        gp("set ylabel 'dg-cl distance (Kpc)'");

	gp("p 'dis_t.dat' title 'dis-t'");

	system("read -p 'Press Enter to continue...' var");
}

