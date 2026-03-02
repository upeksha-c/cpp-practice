/* Write a program that calculates the minimum number of banknotes 
(50, 20, 10, 5, 1) needed to give a requested amount of money.*/

#include <iostream>

using namespace std;

int main(void){
    int value;
    int notes[5] = {50, 20, 10, 5, 1};

    // Prompt the user to enter a value and read it from the input.
    cout << "Enter the value: " << endl;
    cin >> value;

    // Loop through the array of notes
    for(int i =0; i <5; i++) {
        int count = 0;

        //calculate no of notes
        count = value / notes[i];
        //calculate the remaining value after using the notes
        value = value % notes[i];

        // print the notes
        while(count > 0) {
            cout << notes[i] << " ";
            count--;
        }
    }
}