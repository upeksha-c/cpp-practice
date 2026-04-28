/*
Create a class hierarchy consisting of a base class named IPAddress and a derived class named IPAddressChecked.

The base class should store an IP address value. The derived class should extend this by including an additional
boolean flag indicating whether the IP address is valid or not.

Both classes must implement:
- A constructor
- A copy constructor
- A print function

The derived class should reuse the functionality of the base class and extend the print function to also display
whether the IP address is valid ("Correct") or invalid ("Not Correct").

In the main program, read input from the user and create:
- One IPAddress object
- Two IPAddressChecked objects

Finally, print all three objects using their respective print functions.
*/

#include<iostream>
#include<string>

class IPAddress{
    protected:
        std::string address;

    public:
        // Constructor
        IPAddress(std::string address){
            this->address = address;
        }
        // Copy constructor
        IPAddress(const IPAddress &other){
            this->address = other.address;
        }
        virtual void printAddress(){
            std::cout << address << std::endl;
        }
};

class DerivedIP : public IPAddress{
    public:
        DerivedIP(std::string address );
        bool ipIsValid;
        void printAddress();
};

DerivedIP::DerivedIP(std::string address) : IPAddress(address){
    std::string part1, part2, part3, part4;
    int dotCount = 0;
    int dotIndex[3];

    for(size_t i = 0; i < address.length(); i++){
        if(address[i] == '.'){
            if(dotCount < 3){
                dotIndex[dotCount] = i;
            }
                dotCount++;
        }
    }
    if(dotCount != 3){
        std::cout << "Invalid IP address: " << address << " - Incorrect number of dots." << std::endl;
        this->address = "";
        return;
    } else {
        part1 = address.substr(0, (dotIndex[0]-0));
        part2 = address.substr(dotIndex[0]+1, (dotIndex[1]-dotIndex[0]+1));
        part3 = address.substr(dotIndex[1]+1, (dotIndex[2]-dotIndex[1]+1));
        part4 = address.substr(dotIndex[2]+1);

        int num1 = std::stoi(part1);
        int num2 = std::stoi(part2);
        int num3 = std::stoi(part3);
        int num4 = std::stoi(part4);

        if(num1 >= 0 && num1 <= 255 && num2 >= 0 && num2 <= 255 && num3 >= 0 && num3 <= 255 && num4 >= 0 && num4 <= 255){
            this->ipIsValid = true;
        } else {
            std::cout << "Invalid IP address: " << address << " - Each part must be between 0 and 255." << std::endl;
            this->ipIsValid = false;
        }
    }
}

void DerivedIP::printAddress(){
    if(this->ipIsValid){
        std::cout <<  address << " - Correct"<<std::endl;
    } else {
        std::cout << address << " - Not Correct" << std::endl;
    }
}

int main(){
    IPAddress* ip[3];

    ip[0] = new IPAddress("1.2.3.4");
    ip[0]->printAddress();
    ip[1] = new DerivedIP("999.29.29.29");
    ip[1]->printAddress();
    ip[2] = new DerivedIP("199.29.29.29");
    ip[2]->printAddress();

    for(int i = 0; i < 3; i++){
        delete ip[i];
    }
    return 0;
}