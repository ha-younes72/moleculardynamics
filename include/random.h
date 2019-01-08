/******************************************************************************/
/*** Random generator                                                       ***/    
/*** Ver 1.3                                                                ***/
/*** Date: 13910824                                                         ***/
/*** Code implemented in GNU C++ compiler (v. 4.6.3) in 64-bit UBUNTU 12.04 ***/
/*** Run under a Intel® Core™ i3-2330M CPU @ 2.20GHz × 4 machine with 2 GB  ***/
/*** RAM.                                                                   ***/
/******************************************************************************/

/* These routin based on Random number generator based on Numerical recipes in
   C, chapter 7 (ran2)

   double ran2(long *idum);

Long period (> 2 × 10^{18}) random number generator of L. Ecuyer with Bays-Durham shuffle
and added safeguards. Returns a uniform random deviate between 0.0 and 1.0 (exclusive of
the endpoint values). 

***!!! Call with idum a negative integer to initialize; !!!*** thereafter, do not alter
idum between successive deviates in a sequence. RNMX should approximate the largest floating
value that is less than 1. */

#ifndef RANDOM_H

#define RANDOM_H

// Random number generator seed
extern long iseed;

// This is a internal, 32 bit random number generator with uniform Distribution in range [0..1)
double ran2(long *idum);

// Note: idum in rutins argument is random number generator seed if not availible default seed (iseed) is used
// You can initializing random generator seed by usin following function
void Randomize();

// This is a random number generator with Gausssian Distribution (Normal)
double GRand(long *idum);
inline double GRand() { return GRand(&iseed); }

// This is a random generator with uniform Distribution in range [0..1)
inline double Random(long *idum) { return ran2(idum); }
inline double Random() { return ran2(&iseed); }
// This is random generator with uniform distribution in integer range [0..N)
inline int Random(int N, long *idum) { return int(ran2(idum)*N); }
inline int Random(int N) { return int(ran2(&iseed)*N); }
// This is random generator with uniform distribution in range [min..max]
inline double Random(float min, float max, long *idum) { return min + ran2(idum)*(max-min+1); }
inline double Random(float min, float max) { return min + ran2(&iseed)*(max-min+1); }
inline int Random(int min, int max, long *idum) { return int(min + ran2(idum)*(max-min+1)); }
inline int Random(int min, int max) { return int(min + ran2(&iseed)*(max-min+1)); }

#endif
