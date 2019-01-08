#include"../include/header.h"

void MolecularDynamics::returnPosition(ofstream& position){

	//position.open(ios_base::app);
	//position << N <<endl;
	for (int row=0; row<N; row++){
		position << 1 << '\t';
		for (int col=0; col<dimension; col++)
			position << Particles[row].returnr(col) << '\t';
		if (dimension == 2)
			position << 0.0 << '\t';
		position << endl;
		}
	}
