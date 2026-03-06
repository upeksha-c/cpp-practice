#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

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

int dayOfYear(Date date) {

	int noOfDays = date.day;
	int month = date.month -1;
	
	while(month > 0){
	    noOfDays += monthLength(date.year, month);
	    month --;
	}
	
	return noOfDays;
	
}

int main(void) {

	Date d;
	cout << "Enter year, month, day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	return 0;
}