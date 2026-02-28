/* Write a program that examines an integer and counts how many bits are set to 1.
Use an unsigned long variable to hold the number.  */

#include <iostream>

using namespace std;

int main(void) {
    unsigned long num;
    
    cout << "Enter a integer value: ";
    cin >> num;
    
    int count = 0;
    
    while(num > 0) {
       if(num && 1){
           count++;
       }
       num >>= 1;
    }
    cout << "Number of set bits: " << count << endl;
}