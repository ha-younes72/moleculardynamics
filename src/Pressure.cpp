#include"../include/header.h"


double MolecularDynamics::P() {
	
	double sum = 0;
	for (int i=0; i<N; i++)
		for ( int k=0; k<dimension; k++)
			sum += Particles[i].returna(k);
	
	sum /= N;
	return double(N*T)/pow(L,3)-(1.0/dimension)*sum;
	
}
