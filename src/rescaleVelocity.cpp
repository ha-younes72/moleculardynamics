#include"../include/header.h"

void MolecularDynamics::rescaleVelocities() {
	double vSqdSum = 0;
	for (int n = 0; n < N; n++)
		for (int i = 0; i < dimension; i++)
			vSqdSum += Particles[n].returnv(i) * Particles[n].returnv(i);
			
	double lambda = sqrt( 3 * (N-1) * T / vSqdSum );
	for (int n = 0; n < N; n++)
		for (int i = 0; i < dimension; i++)
			Particles[n].changev( i, Particles[n].returnv(i)*lambda ) ;
	}

