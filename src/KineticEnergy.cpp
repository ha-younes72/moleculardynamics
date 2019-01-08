#include"../include/header.h"


double MolecularDynamics::K() {
	
	double sum = 0;
	for (int i=0; i<N; i++)
		for (int j=0; j<dimension; j++)
			sum += Particles[i].returnv(j)*Particles[i].returnv(j);
		
	return 0.5*sum ;
	
}
