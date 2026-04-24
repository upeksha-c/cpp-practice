/*
    Extend the airline booking system to manage multiple flights. Update the command set as follows:

- "create [id] [cap]" : create a new flight with the given ID and seating capacity, starting with 0 reservations
- "delete [id]" : remove the flight with the specified ID
- "add [id] [n]" : add n reservations to the flight with the specified ID
- "cancel [id] [n]" : cancel n reservations from the flight with the specified ID
- "quit" : terminate the program

If any operation fails (e.g., flight not found, capacity limit exceeded, negative reservations, etc.), display the message: "Cannot perform this operation". You may add a more specific message to indicate the reason for failure.

The system can handle a maximum of 10 flights at any time.

Add an accessor method to retrieve a flight's ID. Assume that 0 is not a valid flight ID — a flight with ID 0 is considered nonexistent.

Base your implementation on the code from the previous exercise.

Sample Input 1:
create 101 400
create 307 180
add 101 404
add 307 9
cancel 101 200
delete 101
quit

Expected Output 1:
No flights in the system

Flight 101 : 0/400 (0%) seats reserved

Flight 101 : 0/400 (0%) seats reserved
Flight 307 : 0/180 (0%) seats reserved

Flight 101 : 404/400 (101%) seats reserved
Flight 307 : 0/180 (0%) seats reserved

Flight 101 : 404/400 (101%) seats reserved
Flight 307 : 9/180 (5%) seats reserved

Flight 101 : 204/400 (51%) seats reserved
Flight 307 : 9/180 (5%) seats reserved

Flight 307 : 9/180 (5%) seats reserved

Sample Input 2:
add 101 404
create 101 400
add 101 500
delete 101
cancel 101 200
delete 101
quit

Expected Output 2:
No flights in the system

Cannot perform this operation: flight 101 not found

No flights in the system

Flight 101 : 0/400 (0%) seats reserved

Cannot perform this operation: capacity reached
Flight 101 : 0/400 (0%) seats reserved

No flights in the system

Cannot perform this operation: flight 101 not found
No flights in the system

Cannot perform this operation: flight 101 not found
No flights in the system
*/

#include <iostream>
#include <string>
#include <sstream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  FlightBooking();
  void printStatus();
  bool reserveSeats(int number_ob_seats);
  bool cancelReservations(int number_ob_seats);
  int getId() { return id; };
private:
  int id;
  int capacity;
  int reserved;
  int percentage;
};

FlightBooking::FlightBooking()
{
  id = 0; capacity = 0; reserved = 0;
}
//constructor with values
FlightBooking::FlightBooking(int id, int capacity, int reserved = 0){
  if(reserved < 0){
        reserved = 0;
    }

    if((float(reserved)/capacity)*100 <= 105){
        this -> percentage = (float(reserved)/capacity)*100;
        this -> id = id;
        this -> capacity = capacity;
        this -> reserved = reserved;
    } else {            
        std::cout << "Cannot perform this operation" << std::endl;
    }
}

bool FlightBooking::reserveSeats(int number_ob_seats){
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

// ...

int main() {
  FlightBooking booking[10];

  // Use this to have some starting value
  // booking[0] = FlightBooking(1, 400, 0);
  // booking[0].printStatus();

  std::string command = "";
  int currentBookingIndex = 0;

  //run while entered command is not "quit"
  while (command != "quit")
  {
    std::cout << "What would you like to do?: ";
    std::getline(std::cin, command);

    // handle the command
    std::string action = "";    
    
    
    std::stringstream ss(command);
    ss >> action;
    
    //to check add and cancel operations performed successfully or not
    bool result = false;

    // check for create
    if(action == "create" ){
        int id = 0;
        int cap = 0;
        ss >> id;
        ss >> cap;
        
        if(id == 0){
            std::cout << "Cannot perform this operation" << std::endl;
        } else if(cap <= 0){
            std::cout << "Cannot perform this operation" << std::endl;
        } else{
            booking[currentBookingIndex] = FlightBooking(id, cap);
            if(booking[currentBookingIndex].getId() == id){
                booking[currentBookingIndex].printStatus();
                currentBookingIndex++;
            }
            
        }
    } else if( action == "delete"){
        int id = 0;
        ss >> id;
        if(id != 0){
            bool found = false;
            for(int i=0; i<= currentBookingIndex; i++){ // loop through the bookings to find the booking with the given id
                if(booking[i].getId() == id){
                    booking[i] = FlightBooking();
                    found = true;
                }
            }
            if(!found){ // if the booking with the given id is not found, print an error message
                std::cout << "Invalid booking id " << id << std::endl;
            }
        } else { // if the id is invalid, print an error message
            std::cout << "Invalid booking id " << id << std::endl;
        }
    } else if(action == "add" || action == "cancel"){
        int id = 0;
        int nos = 0;

        ss >> id;
        ss >> nos;

            
        if(nos < 0){
            nos = 0;
        } else if(id != 0){ // if the id is valid, find the booking with the given id and perform the add or cancel operation
            bool found = false;
            int foundIndex = 0;
            bool result = false;
            for(int i=0; i<= currentBookingIndex; i++){
                if(booking[i].getId() == id){
                    found = true;
                    foundIndex = i;
                }
            }
            if(!found){
                std::cout << "Invalid booking id " << id << std::endl;
            } else {
                if(nos < 0){
                    nos = 0;
                } else if(action == "add"){
                    result = booking[foundIndex].reserveSeats(nos);
                } else if(action == "cancel"){
                    result = booking[foundIndex].cancelReservations(nos);
                }

                if (result == false){
                    std::cout << "Cannot perform this operation" << std::endl;
                } else {
                    booking[foundIndex].printStatus();
                }
            }
        } else {
            std::cout << "Invalid booking id " << id << std::endl;
        }
    }
  }

  return 0;
}