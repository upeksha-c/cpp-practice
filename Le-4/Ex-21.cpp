/*
In a networking application, you need to manage IP addresses assigned to different devices. Create a class called Network that stores multiple IPAddress objects using an array.

Your program should provide the following functionality:
- add a single IPAddress to a Network
- display all IP addresses stored in a Network

In the main program:
- create two Network objects
- create five IPAddress objects using user input
- ensure that one of the IP addresses is added to both networks
- add the remaining addresses so that each network has its own set
- print the contents of both networks

Example input:
1.1.1.1
2.2.2.2
3.3.3.3
4.4.4.4
5.5.5.5

Expected output:
Network 1:
1.1.1.1
2.2.2.2
3.3.3.3
Network 2:
3.3.3.3
4.4.4.4
5.5.5.5*/

#include<iostream>
#include<string>

class IPAddress {
    private:
        std::string ip;
    public:
        IPAddress(){};
        void addIP(std::string ip);
        void printIP();
        
};
//add ip address to the class
void IPAddress::addIP(std::string ip){
    this->ip = ip;
}
//function to print ip address
void IPAddress::printIP(){
    std::cout << ip << std::endl;
}

class Network {
    private:
        std::string name;
        IPAddress collectionIP[255];
        int ip_count =0;
    public:
        Network(std::string name);
        std::string getName();
        void addIPAddress(IPAddress ip);
        void printAllAddresses();
};

//constructor to network class
Network::Network(std::string name){
    this->name = name;
}
//to get network name
std::string Network::getName(){
    return name;
}
//set ipaddress to network collection
void Network::addIPAddress(IPAddress ip){
    if(ip_count<255){
        collectionIP[ip_count] = ip;
        ip_count++;
    } else {
        std::cout << "Network " << name << " has reached maximum IP address capacity." << std::endl;
    }
}
//print all ip address in the network
void Network::printAllAddresses(){
    std::cout << "Network " << name << " has the following IP addresses: " << std::endl;
    for(int i=0; i<ip_count; i++){
        collectionIP[i].printIP();
    }
}

int main(){
    //create network array
    IPAddress collection[5];

    //get ip address from user and add to collection
    for(int j=0; j<5; j++){
        std::string ip;
        std::cout<<"Enter the ip address "<< j+1 << " : ";
        std::cin>>ip;
        collection[j].addIP(ip);
    }

    //create 2 networks
    Network network1("1");
    Network network2("2");

    //add ip addresses to networks
    for(int i=0; i<5; i++){
        if(i<2){
            network1.addIPAddress(collection[i]);
        } else if(i==2){
            network1.addIPAddress(collection[i]);
            network2.addIPAddress(collection[i]);
        } else {
            network2.addIPAddress(collection[i]);
        }
    }

    //print all ip addresses in each network
    network1.printAllAddresses();
    network2.printAllAddresses();

    return 0;
}

