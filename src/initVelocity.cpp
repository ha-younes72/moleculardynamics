#include"../include/header.h"

void MolecularDynamics::initVelocities() {
	// Gaussian with unit variance
	for (int n = 0; n < N; n++)
		for (int i = 0; i < dimension; i++)
			Particles[n].changev(i, GRand());

	// Adjust velocities so center-of-mass velocity is zero
	double* vCM = new double [dimension];
	for (int i=0; i < dimension; i++)
		vCM[i] = 0;
			
	for (int n = 0; n < N; n++)
		for (int i = 0; i < dimension; i++)
			vCM[i] += Particles[n].returnv(i);
			
	for (int i = 0; i < dimension; i++)
		vCM[i] /= N;
		
	for (int n = 0; n < N; n++)
		for (int i = 0; i < dimension; i++)
			Particles[n].changev( i, Particles[n].returnv(i)-vCM[i] ) ;
	// Rescale velocities to get the desired instantaneous temperature
	rescaleVelocities();
	}

