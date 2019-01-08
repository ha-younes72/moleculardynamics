#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
//#include "gnuplot-iostream.h"

using namespace std;

class Particle{
	private:
		//int dimension;
		double* r;
		double* v;
		double* a;
		
	public:
		Particle(){
			int dimension = 3;   //Default value;
			r = new double[dimension];
			v = new double[dimension];
			a = new double[dimension];
			for (int i=0; i< dimension; i++){
				r[i] = 0; v[i] = 0; a[i] = 0;
				}
			}

/*		void changedimension(int d){
			dimension = d;
			r = new double[dimension];
			v = new double[dimension];
			a = new double[dimension];
			}
*/		
		double returnr(int i){
			return r[i];
			}
		double returnv(int i){
			return v[i];
			}
		double returna(int i){
			return a[i];
			}
			
		void changer(int i, double rr){
			r[i] = rr;
			}
		void changev(int i, double vv){
			v[i] = vv;
			}
		void changea(int i, double aa){
			a[i] = aa;
			}
		~Particle(){ delete[] r; delete[] v; delete[] a;}
	};
