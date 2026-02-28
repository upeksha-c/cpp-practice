#include <iostream>

using namespace std;

int main(void) {

	unsigned short int val;
	bool ispalindrome = false;

	cout << "value = ";
	cin >> val;

    // variable to hold the original value for later use
    unsigned short int original = val;

    // array to hold the bits of the number.
	int bits[64];
    int i = 0;

    // loop to extract the bits of the number and store them in the array.
    while(val>0) {
        bits[i] = val & 1;
        i++;
        val >>= 1;
    }

    // array to hold the duplicate of the bits for comparison.
    int duplicate[64];

    // loop to reverse the bits and store them in the duplicate array.
    for( int j = i-1; j>=0; j--){
        duplicate[i-j] = bits[j];
    }

    // loop to compare the original bits with the reversed bits to check for palindrome.
    for(int k = 0; k < i; k++) {
        if(bits[k] == duplicate[k]) {
            ispalindrome = true;
        } else {
            ispalindrome = false;
            break;
        }
    }

    // print the result
    if (ispalindrome) {
        cout << original <<" is a bitwise palindrome" << endl;
    } else {
        cout << original << " is not a bitwise palindrome." << endl;
    }
}