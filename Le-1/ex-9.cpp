/*Write a program using structures to input a start time and end time 
(24-hour clock) and calculate the duration between them in hours and minutes.
*/

#include <iostream>

using namespace std;

int main(void){
    struct DateTime{
        int hrs;
        int min;
    } startTime, endTime, duration;
    
    //Prompt start time
    cout << "Enter start time(hours): " << endl;
    cin >> startTime.hrs;
    while(startTime.hrs >= 24 || startTime.hrs < 0){
        cout << "Hours are incorrect. Enter again starting time (hours)" << endl;
        cin >> startTime.hrs;
    }
    
    cout << "Enter start time (minutes):" << endl;
    cin >> startTime.min;
    while(startTime.min >= 60 || startTime.min < 0){
        cout << "Minutes are incorrect. Enter again starting time (minutes)" << endl;
        cin >> startTime.min;
    }
    
    //Prompt end time
    cout << "Enter end time(hours): " << endl;
    cin >> endTime.hrs;
    while(endTime.hrs >= 24 || endTime.hrs < 0){
        cout << "Hours are incorrect. Enter again end time (hours)" << endl;
        cin >> endTime.hrs;
    }
    
    cout << "Enter end time (minutes):" << endl;
    cin >> endTime.min;
    while(endTime.min >= 60 || endTime.min < 0){
        cout << "Minutes are incorrect. Enter again end time (minutes)" << endl;
        cin >> endTime.min;
    }
    
    //calculate the duration
    if (endTime.min < startTime.min){
        endTime.min += 60;
        endTime.hrs--;
    }
    duration.min = endTime.min - startTime.min;
    duration.hrs = endTime.hrs - startTime.hrs;
    
    cout << duration.hrs << ":" << duration.min << endl;
    
}