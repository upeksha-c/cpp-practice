/*Write a C++ program that fills a 10×10 matrix with a multiplication table using pointers only 
(without using indexing or brackets except in the declaration).*/

#include <iostream>

using namespace std;

int main(void) {

	int matrix[10][10] = { };
	int *ptr = &matrix[0][0];
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cout.width(4);
			*(ptr+j+(10*i)) = (i+1)*(j+1);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}