#include "../include/header.h"

void MolecularDynamics::returnVelocity(ofstream& velocity){

	double* vector = new double[N];
	for (int row=0; row<N; row++){
		for (int col=0; col<dimension; col++)
			vector[row]+=pow(Particles[row].returnv(col),2);
		velocity << sqrt(vector[row]) << endl;
		}
	}

