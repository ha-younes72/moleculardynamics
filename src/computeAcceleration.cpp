#include"../include/header.h"

void MolecularDynamics::computeAccelerations() {
	for (int i = 0; i < N; i++)
		for (int k = 0; k < dimension; k++)
			Particles[i].changea( k, 0 ); // set all accelerations to zero
			
	for (int i = 0; i < N-1; i++)
		for (int j = i+1; j < N; j++) {
			double rij[dimension];
			double rSqd = 0;
			for (int k = 0; k < dimension; k++) {
				rij[k] = Particles[i].returnr(k) - Particles[j].returnr(k);
				// closest image convention
				if (fabs(rij[k]) > 0.5 * L) {
					if (rij[k] > 0){
						rij[k] -= L;
						}else{
							rij[k] += L;
							}
					}
				rSqd += rij[k] * rij[k];
				}
			double f = 24 *(2 * pow(rSqd, -7) - pow(rSqd, -4));
			for (int k = 0; k < dimension; k++) {
				Particles[i].changea( k, Particles[i].returna(k) + (rij[k] * f)/sqrt(rSqd) );
				Particles[j].changea( k, Particles[j].returna(k) - (rij[k] * f)/sqrt(rSqd) );
				}
			}
	}

