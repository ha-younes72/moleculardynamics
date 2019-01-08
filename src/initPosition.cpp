#include"../include/header.h"

void MolecularDynamics::initPositions() {

	if (dimension == 3){
		// find M large enough to fit N atoms on an fcc lattice
		int M = 1;
		while (4 * M * M * M < N)  ++M;
		double lc = L / M; // lattice constant of conventional cell

		// 4 atomic positions in fcc unit cell
		double xCell[4] = {0.25,0.75, 0.75, 0.25};
		double yCell[4] = {0.25,0.75, 0.25, 0.75};
		double zCell[4] = {0.25,0.25, 0.75, 0.75};
	
		int n = 0;
		// atoms placed so far
		for (int x = 0; x < M; x++)
			for (int y = 0; y < M; y++)
				for (int z = 0; z < M; z++)
					for (int k = 0; k < 4; k++)
						if (n < N) {
							Particles[n].changer(0, (x + xCell[k]) * lc);
							Particles[n].changer(1, (y + yCell[k]) * lc);
							Particles[n].changer(2, (z + zCell[k]) * lc);
							++n;
							}
		}else{
			
			int n = sqrt(N);  // number of atoms in each direction
    			//n=1;
			//while (2 * n * n < N)  ++n;
	    		double lc = L / n;                  // lattice spacing
	    		//for (int i = 0;  i< N; i++)
			int u =0;
			for (int j=1; j<n+1; j++)
				for (int k=1; k<n+1; k++)
	        			if (u < N+1) {
					        Particles[u].changer(0, j*lc-0.5);
						Particles[u].changer(1, k*lc-0.5);
						++u;
						}
				
			// find M large enough to fit N atoms on an fcc lattice
/*			int M = 1;
			while (2 * M * M < N)  ++M;
			double lc = L / M; // lattice constant of conventional cell
	
			// 4 atomic positions in fcc unit cell
			double xCell[4] = {0.25,0.75, 0.75, 0.25};
			double yCell[4] = {0.25,0.75, 0.25, 0.75};
			double zCell[4] = {0.25,0.25, 0.75, 0.75};
		
			int n = 0;
			// atoms placed so far
			for (int x = 0; x < M; x++)
				for (int y = 0; y < M; y++) //for (int z = 0; z < M; z++)
						for (int k = 0; k < 4; k++)
							if (n < N) {
								Particles[n].changer(0) = (x + xCell[k]) * lc;
								Particles[n].changer(1) = (y + yCell[k]) * lc;
								++n;
								}
*/
			}
	}	

