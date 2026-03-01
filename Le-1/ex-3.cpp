/*
    Write a program that acts as a simple calculator. It should support the four basic operations:
    - Addition (+)
    - Subtraction (-)
    - Multiplication (*)
    - Division (/)

    The program should display a menu like this:

    MENU:
    0 - Exit
    1 - Addition
    2 - Subtraction
    3 - Multiplication
    4 - Division
*/



#include <iostream> // include the iostream library for input and output operations.

using namespace std;//this namespace is used to avoid writing std:: before every standard library function.

int main(void) {
    int choice; // variable to hold the user's menu choice.

    cout << "MENU: " << endl;
    cout << "0 - exit" <<endl;
    cout << "1 - addition" << endl;
    cout << "2 - subtraction" << endl;
    cout << "3 - multiplication" << endl;
    cout << "4 - division" << endl;
    cout << "Your choice?" << endl;

    cin >> choice; // read the user's choice from the input.

    double num1, num2; // variables to hold the two numbers for the arithmetic operations.

    switch (choice) {
        case 0:
            cout << "Exiting the program." << endl;
            break; // exit the program.
        case 1:
            cout << "Enter number 1: ";
            cin >> num1; // read the first number.

            cout << "Enter number 2: ";
            cin >> num2; // read the second number.

            cout << "Result : " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Enter number 1: ";
            cin >> num1; // read the first number.

            cout << "Enter number 2: ";
            cin >> num2; // read the second number.

            cout << "Result : " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Enter number 1: ";
            cin >> num1;

            cout << "enter number 2: ";
            cin >> num2;

            cout << "Result : " << num1 * num2 << endl;
            break;
        case 4: 
            cout << "Enter number 1: ";
            cin >> num1;

            cout << "Enter number 2: ";
            cin >> num2;

            cout << "Result: " << num1/num2 <<endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option from the menu." << endl;
    }
}