#include"./include/header.h"


int main() {
	

	cout << "/*****************************************************************************************/" << endl <<
		"/***                                                                                   ***/" << endl <<
		"/***  Computational Physics:: Molecular Dynamics ;                                     ***/" << endl <<
		"/***  Copyright (c) 2015, Y. H. Abdollahi.                                             ***/" << endl <<
		"/***                                                                                   ***/" << endl <<
		"/***  This code has been written to show an example of Molecular Dynamics.             ***/" << endl <<
		"/***                                                                                   ***/" << endl <<
		"/***  Code implemented in GNU C++ compiler (v. 4.6.3) in 64-bit Fedora 21 , Tested     ***/" << endl <<
		"/***  under an Intel® Core™ i5-2430M CPU @ 2.40GHz × 4 machine with 4 GB RAM.          ***/" << endl <<
		"/***  Data files are in data directory.                                                ***/" << endl <<
		"/***************************************** That's IT!!!***********************************/" << endl;

	int N = 64;
	double rho = 1;
	double T = 150;

	MolecularDynamics MD(N, rho, T, 2);
	MD.initialize();
	double dt = 0.00001;
	ofstream file("T2.data");
	ofstream position("positiondata.xyz");
	ofstream velocity("velocity.data");
	ofstream Energy("TotalEnergy.data");
	ofstream KineticEnergy("KineticEnergy.data");
	ofstream PotentialEnergy("PotentialEnergy.data");
	ofstream Pressure("Pressure.data");
	
	file << MD.instantaneousTemperature() << '\n';
	position << N << '\n' << "Atoms\n";
	MD.returnPosition(position);
	
	double t = 0.0;
	for (int i = 0; i < 30000; i++) {
		MD.velocityVerlet(dt);
		file << t << '\t' << MD.instantaneousTemperature() << '\n';
		if (i % 20 == 0)
			MD.rescaleVelocities();
		t += dt;
		}

	double dT = 0.1;

	for (int k =0; T>0.1; k++){
		MD.setT(T-=dT);
		position << N << '\n' << "Atoms\n";
		for (int i = 0; i < 200; i++) {
			MD.velocityVerlet(dt);
			file << t << '\t' << MD.instantaneousTemperature() << '\n';
			if (i % 20 == 0)
				MD.rescaleVelocities();
			t += dt;
			}
		Energy << T << '\t' << MD.E() << endl;
		KineticEnergy <<  T << '\t' << MD.K() << endl;
		PotentialEnergy <<  T << '\t' << MD.U() << endl;
		Pressure << T << '\t' << MD.P() << endl;
		MD.returnVelocity(velocity);
		MD.returnPosition(position);
		}

	file.close();
	velocity.close();
	position.close();
	//MD.plot();

	}
