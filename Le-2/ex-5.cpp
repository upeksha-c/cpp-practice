/*Write a C++ function named `monthLength` that takes a year and a month as integers 
and returns the number of days in that month 
(considering leap years) or 0 if the inputs are invalid.*/

#include <iostream>

using namespace std;

bool isLeap(int year) { 

	bool result;
	result = year % 4 == 0;
	return result;
}

int monthLength(int year, int month) {
    int days;

	switch(month){
	    case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
	        days = 31;
	        break;
	    case 2:
	        days = isLeap(year) ? 29 : 28;
	        break;
	    case 4: case 6: case 9: case 11: 
	        days = 30;
	        break;
	    default: 
	        days = 0;
	}
	return days;
}

int main(void) {

	for(int yr = 2000; yr < 2002; yr++) {
		for(int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr,mo) << " ";
		cout << endl;
	}
	return 0;
}