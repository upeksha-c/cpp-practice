/* // Write a program that calculates arithmetic, harmonic, geometric, 
and root mean square values for a set of numbers using loops. */

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
	double ArithmeticMean;
	double HarmonicMean;
	double GeometricMean;
	double RootMeanSquare;

	// ArithmeticMean
	double sum = 0;
	for (int i = 0; i<n; i++){
	    sum += vector[i];
	}
	ArithmeticMean = sum/n;
	
	// HarmonicMean
	double sum2 = 0;
	for (int i = 0; i<n; i++){
	    sum2 += 1/vector[i];
	}
	HarmonicMean = n/sum2;
	
	// GeometricMean
	double sum3 = 1;
	for (int i = 0; i<n; i++){
	    sum3 *= vector[i];
	}
	GeometricMean = pow(sum3,(1.0/n));
	
	// RootMeanSquare
	double sum4 = 0;
	for (int i = 0; i<n; i++){
	    sum4 += pow(vector[i],2);
	}
	RootMeanSquare = pow((sum4/n),(1.0/2));

	cout << "Arithmetic Mean = " << ArithmeticMean << endl;
	cout << "Harmonic Mean   = " << HarmonicMean   << endl;
	cout << "Geometric Mean  = " << GeometricMean  << endl;
	cout << "RootMean Square = " << RootMeanSquare << endl;

	cout << endl;
	return 0;

}