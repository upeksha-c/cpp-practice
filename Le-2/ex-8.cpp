//calculate the no of days you have lived till tomorrow
//Write a C++ function returns the current date as a Date structure using system time functions.

#include <iostream>
#include <ctime>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

//check if leap year
bool isLeap(int year) { 
	bool result;
	result = year % 4 == 0;
	return result;
}

//ckeck the number of days in a month
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

//check the day number within the year
int dayOfYear(Date date) {
	int noOfDays = date.day;
	int month = date.month -1;
	
	while(month > 0){
	    noOfDays += monthLength(date.year, month);
	    month --;
	}
	
	return noOfDays;
	
}

//check the number of days between two dates
int daysBetween(Date d1, Date d2) {

	//Return -1 if till date earlier than since
	if(d1.year > d2.year){
	    return -1;
	} else if((d1.year == d2.year) && (d1.month > d2.month)){
	    return -1;
	} else if((d1.year == d2.year) && (d1.month == d2.month) && (d1.day > d2.day)){
	    return -1;
	}
	
	
	// cumulativeDays variable to hold the total number of days between the two dates.
	int cumulativeDays;

    if (d1.year == d2.year){
        // check if the two dates are in the same year. If so, calculate the difference .
        cumulativeDays = dayOfYear(d2)- dayOfYear(d1);
        return cumulativeDays ;
    } else {
        //calculate the difference if the two dates are in different years.
        if(isLeap(d1.year)){
            cumulativeDays = 366-dayOfYear(d1);
        } else {
            cumulativeDays = 365-dayOfYear(d1);
        }
        
        // loop to add the number of days in the years between the two dates.
        int year1 = d1.year + 1;
        
        while(year1 < d2.year){
            if(isLeap(year1)){
                cumulativeDays += 366;
            } else {
                cumulativeDays += 365;
            }
            year1++;
        }
        
        cumulativeDays += dayOfYear(d2);
    }
	return cumulativeDays;

}

Date getCurrentDate(void) {
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    Date currentDate;
    
    currentDate.year = tl.tm_year + 1900;
    currentDate.month = tl.tm_mon + 1;
    currentDate.day = tl.tm_mday;

    return currentDate;
}

int main(void) {

	Date birthDay;
	cout << "Enter your birth date (y m d): ";
	cin >> birthDay.year >> birthDay.month >> birthDay.day;
	
	cout << daysBetween(birthDay, getCurrentDate()) << endl;
	return 0;
}
