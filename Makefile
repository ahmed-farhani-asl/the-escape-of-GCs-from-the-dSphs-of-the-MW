all:
	g++ escRate.h gnuplot.h plot.cpp define.cpp inidg.cpp RK10th.cpp acc.cpp MW.cpp tf.cpp escV.cpp mdg.cpp iniV.cpp tcross.cpp maxwell.cpp maxwell_rand.cpp write.cpp main.cpp -o run

clean:
	rm run cl.dat dg.dat dg-cl.dat dis_t.dat
