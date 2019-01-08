#include"../include/header.h"


double MolecularDynamics::U() {

	double sum = 0;
	for (int i = 0; i < N-1; i++)
		for (int j = i+1; j < N; j++) {
			double rij[dimension];
			double rSqd = 0;
			for (int k = 0; k < dimension; k++) {
				rij[k] = Particles[i].returnr(k) - Particles[j].returnr(k);
				rSqd += rij[k] * rij[k];
				}
			sum += 4 *(pow(rSqd, -6) - pow(rSqd, -3));
			}
		
	return -sum ;
	
}
