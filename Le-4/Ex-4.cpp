/*  
    You have been tasked with developing a simple module for an airline's flight booking system. Each flight record contains a flight number, the aircraft's total seat capacity, and the number of seats already reserved.

Write a program that displays a status report showing what percentage of the aircraft's capacity has been filled. The report should be printed in the following format:

Flight [number] : [reserved]/[capacity] ([percentage]%) seats reserved

For this exercise, assume that reserved seats may exceed the capacity — you will add validation logic in a later task.

Sample Input 1:
100
50

Sample Output 1:
Flight 1 : 50/100 (50%) seats reserved

Sample Input 2:
180
200

Sample Output 2:
Flight 1 : 200/180 (111%) seats reserved
*/

#include <iostream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
private:
  int id;
  int capacity;
  int reserved;
  int percentage;
};

void FlightBooking::printStatus()
{
  // print report here
  std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << "(" << percentage << "%) seats taken";
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  // Save data to members
  this -> id = id;
  this -> capacity = capacity;
  this -> reserved = reserved;
  this -> percentage = (float(reserved)/capacity)*100;
}

int main() {
  int reserved = 0,
      capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;

  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  booking.printStatus();

  return 0;
}