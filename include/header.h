#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
//#include "gnuplot-iostream.h"
#include "Particle.h"
#include "random.h"

using namespace std;

class MolecularDynamics{

private:
	// simulation parameters
	int N;
	double rho;
	double T;
	double L; // linear size of cubical volume
	int dimension;
	Particle* Particles;
	//double **r;// positions
	//double **v;// velocities
	//double **a;// accelerations

public:

	MolecularDynamics(int number, double density, double dama, int d){
		dimension = d;
		N = number; rho = density; T = dama;
		// compute side of cube from number of particles and number density
		L = pow(double(N) / rho, 1.0/double(dimension));
		//cout << "L is : " << L << endl;
		//r = new double* [N];
		//v = new double* [N];
		//a = new double* [N];
		Particles = new Particle [N];
	//	if (dimension == 2)
	//		for (int i = 0; i < N; i++) 
	//			Particles[i].changedimension(dimension);
		}

	// function declarations
	void initialize(); // allocates memory, calls following 2 functions
	void initPositions();//places particles on an fcc lattice
	void initVelocities();//initial Maxwell-Boltzmann velocity distribution
	void rescaleVelocities();//adjust the instanteous temperature to T
	void computeAccelerations();
	void velocityVerlet(double dt); 
	double instantaneousTemperature();//compute the instanteous temperature
	void setT (double dama){T = dama;};
	void returnPosition(ofstream& position);
	void returnVelocity(ofstream& velocity);
	
	double E();			//Total Energy
	double K();			//Kinetic Energy
	double U();			//Potential Energy
	double P();			//Pressure
	//~MolecularDynamics(){delete [] Particles;};

};
