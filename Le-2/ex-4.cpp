/*Write a C++ function named isLeap that takes a year as an integer and returns true if 
the year is a leap year and false otherwise, without printing anything.*/
#include <iostream>
using namespace std;

bool isLeap(int year) { 
	bool result;
	result = year % 4 == 0;
	return result;

}

int main(void) {

	for(int yr = 1995; yr < 2017; yr++) 
		cout << yr << " -> " << isLeap(yr) << endl;
	return 0;
}