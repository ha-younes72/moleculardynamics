#include"../include/header.h"

/*double MolecularDynamics::gasdev () {
	static bool available = false;
	static double gset;
	double fac, rsq, v1, v2;
	if (!available) {
		do {
			v1 = 2.0 * rand() / double(RAND_MAX) - 1.0;
			v2 = 2.0 * rand() / double(RAND_MAX) - 1.0;
			rsq = v1 * v1 + v2 * v2;
			} while (rsq >= 1.0 || rsq == 0.0);
		fac = sqrt(-2.0 * log(rsq) / rsq);
		gset = v1 * fac;
		available = true;
		return v2*fac;
		} else {
			available = false;
			return gset;
			}
	}
*/
