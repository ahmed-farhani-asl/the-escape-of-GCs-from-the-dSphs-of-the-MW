
#include "escRate.h"

int main(){	

	define();
	
	srand(time(0));
	
	for(xdg=8.5; xdg<=300.0; xdg+=0.1*xdg){
	
		for(ecc=0.0; ecc<1; ecc+=0.05){

			inidg();
		
			for(layer=1; layer<=10; layer++){

				double dradj=tr/113.330078125;

				drdg = pow(1.5, layer-1)*dradj;
				
				rdg += drdg;
				
				if(esc/repeat>=0.95){
				
					escRate += 1.0*(mdg(rdg)-mdg(rdg-drdg))/mdg(tr);

					cout<<"layer = "<<layer<<'\t'<<"esc = "<<esc<<'\t'<<"escRate = "<<escRate<<'\t'<<"repeat"<<k<<endl; 
					
					continue;
				}

				esc=0;
			
				k=repeat;
				
				for(int i=1; i<=k; i++){
					
					double rcl = drdg*((double) rand() / RAND_MAX) + (rdg-drdg);
	
					phi = 2*phi*((double) rand()/RAND_MAX);
					theta = phi*((double) rand()/RAND_MAX);

					mrv[1][1] = rcl*cos(phi)*sin(theta) + mrv[0][1];
					mrv[1][2] = rcl*sin(phi)*sin(theta) + mrv[0][2];
					mrv[1][3] = rcl*cos(theta) + mrv[0][3];

					double vcl = maxwell_rand(0.5*escV(rcl)); 
	
					phi = 2*phi*((double) rand()/RAND_MAX);
					theta = phi*((double) rand()/RAND_MAX);
	
					mrv[1][4] = vcl*cos(phi)*sin(theta) + mrv[0][4];
					mrv[1][5] = vcl*sin(phi)*sin(theta) + mrv[0][5];
					mrv[1][6] = vcl*cos(theta) + mrv[0][6];

					T = tcross(rcl);
					
					dis = rcl;
					
					accept = true;
					
					double tempdis, mindis;
			/*				
					w[0].open("dg.dat", ios::out);
					w[1].open("cl.dat", ios::out);
					w[2].open("dg-cl.dat", ios::out);
					w[3].open("dis_t.dat", ios::out);
			*/		
					for(t=0; t<=tcrit; t++){
						
						tempdis = dis;
						
						RK10th();
						
						if(dis-mindis>2*tr){
							
							if(t*dt<10*T/layer){
								
								k++;
								accept=false;
								break;
							}
							else{

								esc++;
								break;
							}
						}
						
						if(dis<=tempdis) mindis=dis;

						write();
						
					} // time
						
					if(accept==true) cout<<dis<<'\t'<<'\t'<<tr<<'\t'<<'\t'<<esc<<endl;
					
			//		for(int ii=0; ii<4; ii++)
			//			w[ii].close();
					
			//		if(accept==true) plot();
					
				} // repeat
				
				escRate += esc*(mdg(rdg)-mdg(rdg-drdg))/(mdg(tr)*repeat);
				
				cout<<"layer = "<<layer<<'\t'<<"esc = "<<esc<<'\t'<<"escRate = "<<escRate<<'\t'<<"repeat "<<k<<endl;
			//	cout<<"layer = "<<layer<<'\t'<<"esc = "<<esc<<'\t'<<"escRate = "<<escRate<<'\t'<<"rdg = "<<rdg<<'\t'<<"drdg = "<<drdg<<endl;
				
			} // layer

			cout<<"xdg = "<<xdg<<'\t'<<"ecc = "<<ecc<<endl;
			cout<<"escRate = "<<escRate<<endl;
			
		} // ecc
	} // xdg
}	

