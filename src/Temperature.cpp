#include"../include/header.h"

double MolecularDynamics::instantaneousTemperature() {
	
	double sum = 0;
	for (int i = 0; i < N; i++)
		for (int k = 0; k < dimension; k++)
			sum += Particles[i].returnv(k) * Particles[i].returnv(k);
	//if (T>0){
		return sum / (3 * (N - 1));
		//}else{
			//return sum / (3 * (N - 1));
			//}
	}

