
#include "escRate.h"

void write(){
/*	
	if(t==0){
		
		w1.open("dg.dat", ios::out);
		w2.open("cl.dat", ios::out);
		w3.open("dg-cl.dat", ios::out);
		w4.open("dis_t.dat", ios::out);
	}
*/
	w[0]<<t*dt<<'\t'<<mrv[0][1]<<'\t'<<mrv[0][2]<<'\t'<<mrv[0][3]<<endl;
	
	w[1]<<t*dt<<'\t'<<mrv[1][1]<<'\t'<<mrv[1][2]<<'\t'<<mrv[1][3]<<endl;
	
	w[2]<<t*dt<<'\t'<<mrv[1][1] - mrv[0][1]<<'\t'<<mrv[1][2] - mrv[0][2]<<'\t'<<mrv[1][3] - mrv[0][3]<<endl;

	w[3]<<t*dt<<'\t'<<dis<<endl; 

}
