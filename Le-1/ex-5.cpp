
/*Write a program to check whether a given vector contains a palindrome */

#include <iostream>

using namespace std;

int main(void) {

	int vector[] = {1, 7, 3, 8, 3, 3, 1};
	bool ispalindrome = true;
    // Calculate the number of elements in the vector.
	int n = sizeof(vector) / sizeof(vector[0]);

	// Insert your code here
	for(int i=0; i<(n/2); i++){
	    if(vector[i] != vector[n-1-i]){
	        ispalindrome = false;
	        break;
	    }
	}

	if(ispalindrome)
		cout << "It's a palindrome";
	else
		cout << "It isn't a palindrome";
	cout << endl;
	return 0;
}