/*
    Develop a program to manage gym member subscriptions. For each member, store:
- user ID
- name
- number of months their membership is valid

The program must support the following commands:

- "create [id] [name]" : create a new member with the given ID and name, starting with 0 months of subscription
- "delete [id]" : remove the member with the specified ID
- "extend [id] [n]" : add n months to the membership duration of the member with the specified ID
- "cancel [id]" : set the membership duration of the specified member to 0
- "quit" : terminate the program

If any operation fails (e.g., member not found, ID already exists, etc.), display the message: "Cannot perform this operation". You may add additional details to explain why the operation failed.

The system can handle a maximum of 10 members at any time.

Assume that 0 is not a valid member ID — an ID of 0 means the member does not exist.

Sample input:
create 7 John Doe
create 8 Jane Doe
extend 7 6
extend 8 12
cancel 8
delete 7
quit

Expected output:
No members in the system

Member 7 : John Doe, subscription valid for 0 months

Member 7 : John Doe, subscription valid for 0 months
Member 8 : Jane Doe, subscription valid for 0 months

Member 7 : John Doe, subscription valid for 6 months
Member 8 : Jane Doe, subscription valid for 12 months

Member 7 : John Doe, subscription valid for 6 months
Member 8 : Jane Doe, subscription valid for 0 months

Member 8 : Jane Doe, subscription valid for 0 months
*/



#include<iostream>
#include<string>
#include<sstream>

class GymMembership{
    private:
        int id;
        std::string name;
        int no_months;
        
    public:
        GymMembership(int id, std::string name, int no_months);
        GymMembership();
        int getId(){ return id;}
        void printDetails();
        void extendMembership(int months);
        void cancelSubscription();
    
};

//declare the constructors
GymMembership::GymMembership(){
    id = 0;
    name = "";
    no_months = 0;
}

GymMembership::GymMembership(int id, std::string name, int no_months = 0){
    this -> id = id;
    this -> name = name;
    this -> no_months = no_months;
}

//declare extend method
void GymMembership::extendMembership(int months){
    no_months +=months;
}

//implement printdetails methos
void GymMembership:: printDetails(){
    std::cout << "Member " << id << " : " << name << ", subscription valid for " << no_months << " months" << std::endl;
}

//implement cancelSubscription method
void GymMembership::cancelSubscription(){
    no_months = 0;
}

int main(){
    GymMembership membership[10];
    std::string command = "";
    
    //make a variable to hold current member index
    int currentIndex = 0;
    //make variable to check if id exists
    bool found = false;
    int foundIndex=0;
    
    //request cammands till enter the quit
    while (command != "quit"){
        //variable to hold input
        std::string action = "";
        
        //ask for a command
        std::cout << "What you need to do : ";
        std::getline(std::cin, action);
        
        //separate the input
        std::stringstream ss(action);
        ss >> command;
        
        //if command is create, make a new member
        if(command == "create"){
            std::string name;
            std::string name2;
            int id;
            
            ss >> id;
            ss >> name;
            ss >> name2;
            
            name = name + " " + name2;
            
            //create new member
            membership[currentIndex] = GymMembership(id, name);
            if(membership[currentIndex].getId() == id ){
                currentIndex++;
                membership[currentIndex-1].printDetails();
            }
        } else if(command == "delete"){
            int id;
            
            ss >> id;
            
            for (int i=0; i< currentIndex; i++){
                if(membership[i].getId() == id){
                    found = true;
                    foundIndex= i;
                    break;
                }
            }
            
            if(found){
                membership[foundIndex] = GymMembership();
                std::cout << "Member deleted" << std::endl;
                found = false;
                foundIndex = 0;
            } else {
                std::cout << "Member not exists" << std::endl;
            }
        } else if(command == "extend"){
            int id, months;
            
            ss >> id >> months;
            
            for (int i=0; i< currentIndex; i++){
                if(membership[i].getId() == id){
                    found = true;
                    foundIndex= i;
                    break;
                }
            }
            
            if(found){
                membership[foundIndex].extendMembership(months);
                membership[foundIndex].printDetails();
                found = false;
                foundIndex = 0;
            } else {
                std::cout << "Member not exists" << std::endl;
            }
        } else if(command == "cancel"){
            int id;
            
            ss >> id;
            
            for (int i=0; i< currentIndex; i++){
                if(membership[i].getId() == id){
                    found = true;
                    foundIndex= i;
                    break;
                }
            }
            
            if(found){
                membership[foundIndex].cancelSubscription();
                membership[foundIndex].printDetails();
                found = false;
                foundIndex = 0;
            } else {
                std::cout << "Member not exists" << std::endl;
            }
        } else if(command != "quit"){
            std::cout << "Command not identified" << std::endl;
        }
        
        
    }
    return 0;
}