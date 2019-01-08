#include"../include/header.h"


void MolecularDynamics::velocityVerlet(double dt) {
	computeAccelerations();
	//double* g = new double[3];
	//g[0]=0; g[1]=0; g[2]=-1.0;

	for (int i = 0; i < N; i++)
		for (int k = 0; k < dimension; k++) {
			Particles[i].changer(k, Particles[i].returnr(k) + Particles[i].returnv(k) * dt + 0.5 * Particles[i].returna(k) * dt * dt);
			// use periodic boundary conditions
			if (Particles[i].returnr(k) < 0){
				Particles[i].changer(k, Particles[i].returnr(k) + L);
				//r[i][k] = 0;
				//v[i][k] = -v[i][k];
				}

			if (Particles[i].returnr(k) >= L){
				Particles[i].changer(k, Particles[i].returnr(k) - L);
				//r[i][k] = (2*L)-r[i][k];
				//v[i][k] = -v[i][k];
				}
			Particles[i].changev(k, Particles[i].returnv(k) + 0.5 * Particles[i].returna(k) * dt);
			}
		computeAccelerations();
		for (int i = 0; i < N; i++)
			for (int k = 0; k < dimension; k++)
				Particles[i].changev(k, Particles[i].returnv(k) + 0.5 * Particles[i].returna(k) * dt);
	}

