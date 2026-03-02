/*Write a program to check whether a square 2D array (matrix) is symmetric across its main diagonal.*/

#include <iostream>

using namespace std;

int main(void) {

	double matrix[][4] = { 	{ 1, 2, 3, 4 },
			    	{ 2, 2, 3, 1 },
			    	{ 3, 3, 3, 2 },
			    	{ 4, 1, 2, 4 }};

	int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	int rows= sizeof(matrix) / sizeof(matrix[0]);
	bool issymmetric = true;

    // Check if the matrix is square. If not, it cannot be symmetric.
    if(side != rows) {
        issymmetric = false;
    } else { //if square, check if it is symmetric
        for(int i=0; i<rows; i++ ){
            for(int j=0; j<side; j++){
                if(matrix[i][j] != matrix[j][i]){
                    issymmetric = false;
                    break;
                }
            }
        }
    }
	

	if(issymmetric)
		cout << "The matrix is symmetric" << endl;
	else
		cout << "The matrix is not symmetric" << endl;
	return 0;
}