/* Write a C++ function named isPrime that takes an integer 
and returns true if the number is prime, otherwise false.
*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if(num < 2){
        return false;
    } 
    
    int occurance = 2;
    
    while(occurance <= sqrt(num)){
        if(num % occurance == 0){
            return false;
        }
        occurance++;
    }
    
    return true;
}

int main(void) {
	for(int i = 0; i <= 21; i++)
		if(isPrime(i))
			cout << i << " ";
	cout << endl;
	return 0;
}