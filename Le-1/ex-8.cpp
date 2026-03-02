/*write a program that uses a structure to store time (hours and minutes) and calculates 
the new time after adding a given number of minutes.*/

#include <iostream>

using namespace std;

int main(void){
    struct DateTime {
        int hours;
        int min;
    } eventDate;
    
    int duration;
    
    // Prompt the user to enter the starting time 
    cout << "Enter starting time (hours)" << endl;
    cin >> eventDate.hours;
    while(eventDate.hours >= 24 || eventDate.hours < 0){
        cout << "Hours are incorrect. Enter again starting time (hours)" << endl;
        cin >> eventDate.hours;
    }
    
    cout << "Enter starting time (minutes)" << endl;
    cin >> eventDate.min;
    while(eventDate.min >= 60 || eventDate.hours < 0){
        cout << "Minutes are incorrect. Enter again starting time (minutes)" << endl;
        cin >> eventDate.min;
    }
    
    // Prompt the user to enter the duration of the event in minutes.
    cout << "Enter duration (minutes)" << endl;
    cin >> duration;
    while(duration < 0){
        cout << "Duration is incorrect. Enter again duration (minutes)" << endl;
        cin >> duration;
    }
    
    // Calculate the ending time of the event by adding the duration to the starting time.
    if (duration >= 60) {
        // Calculate the number of hours to add and the remaining minutes.
        int addHours = duration/60;
        int remMin = duration % 60;
        
        //add minutes to starting time minutes. if exceed 60 add 1 hour
        eventDate.min += remMin;
        if (eventDate.min >= 60){
            eventDate.min = eventDate.min% 60;
            addHours++;
        }
        //add hours to starting time hours. if exceed 24, divide 24 and get only the remainder.
        eventDate.hours += addHours;
        if(eventDate.hours >= 24){
            eventDate.hours = eventDate.hours % 24;
        }
    }
    
    cout << eventDate.hours << ":" << eventDate.min <<endl;
}