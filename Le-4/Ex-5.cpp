/*
Continue developing the airline booking system. Previously, there was no limit on reserved seats.

Airlines often allow overbooking up to 105% of capacity. Modify the constructor so that reserved seats cannot exceed 105% of total capacity. If a negative number of reservations is given, set it to 0.

Also allow users to add or cancel reservations through a simple interface:
- "add [n]" : try to add n reservations
- "cancel [n]" : try to cancel n reservations
- "quit" : stop the program

If an operation fails, display: "Cannot perform this operation"
*/


#include <iostream>
#include <string>
#include <sstream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
  bool reserveSeats(int number_ob_seats);
  bool cancelReservations(int number_ob_seats);
private:
  int id;
  int capacity;
  int reserved;
  int percentage;
};
// ...
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    if(reserved < 0){
        reserved = 0;
    }

    if((float(reserved)/capacity)*100 <= 105){
        this -> percentage = (float(reserved)/capacity)*100;
        this -> id = id;
        this -> capacity = capacity;
        this -> reserved = reserved;
    } else {
        this-> reserved = 105*capacity/100;
        this -> percentage = 105;
        this -> id = id;
        this -> capacity = capacity;
        std::cout << "Cannot perform this operation" << std::endl;
    }
  
}

bool FlightBooking::reserveSeats(int number_ob_seats)
{
  // try to add reservations and return 'true' on success
  if(percentage < 105){
    reserved += number_ob_seats;
    percentage = (float(reserved)/capacity)*100; 
    return true;
  } else {
    // keep the limits in mind
    return false;
  }
}
void FlightBooking::printStatus()
{
  std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << "(" << percentage << "%) seats taken" << std::endl;
}

bool FlightBooking::cancelReservations(int number_ob_seats)
{
  // try to cancel reservations and return 'true' on success
  // keep the limits in mind
  if(reserved > 0 && reserved - number_ob_seats >= 0){
    reserved -= number_ob_seats;
    percentage = (float(reserved)/capacity)*100; 
    return true;
  } else {
    // keep the limits in mind
    return false;
  }
}

int main() {
  int reserved = 0;
  int capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;

  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;
  std::cin.ignore(); 

  FlightBooking booking(1, capacity, reserved);

  std::string command = "";
  while (command != "quit")
  {
    std::cout << "What would you like to do?: ";
    getline(std::cin,command);

    // handle the command
    std::string action = "";
    int nos = 0;
    
    std::stringstream ss(command);
    ss >> action;
    
    bool result = false;

    if(action == "add" || action == "cancel"){
        ss >> nos;
            if(nos < 0){
                nos = 0;
            } else if(action == "add"){
                result = booking.reserveSeats(nos);
            } else if(action == "cancel"){
                result = booking.cancelReservations(nos);
            }
    }

    if (result == false){
        std::cout << "Cannot perform this operation" << std::endl;
    } else {
        booking.printStatus();
    }
  }

  return 0;
}