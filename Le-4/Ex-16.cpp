/*
This program demonstrates the use of inheritance and polymorphism.

A base class represents a general game piece and declares a virtual
function to verify whether a move is valid.

Two derived classes (Man and King) implement this function based on
their movement rules:
- A Man moves one step diagonally forward.
- A King can move any number of steps diagonally in any direction.

In main(), objects of both types are accessed through base class
pointers, and their move validation methods are tested.

Test Data
Call a method to check if Piece(Man) can be moved from b1 to c2
Call a method to check if Piece(King) can be moved from b1 to d3
Call a method to check if Piece(Man) can be moved from b1 to d3
*/

#include<iostream>
#include<string>
#include<cmath>

class Pieces {
    public:
        virtual bool isMoveValid(std::string from, std::string to) = 0;

    protected:
        bool isLetterValid(char letter) {
            if (letter>='a' && letter<='h') {
                return true;
            } else {
                return false;
            }
        }
        bool isNumberValid(char number) {
            if (number>='1' && number<='8') {
                return true;
            } else {
                return false;
            }
        }
};

class Man: public Pieces {
    public:
        bool isMoveValid(std::string from, std:: string to);
};

bool Man::isMoveValid(std::string from, std::string to){

    bool moveValid = false;

    // Extracting the letter and number from the input strings
    char fromLetter = from[0];
    char fromNo = from[1];
    char toLetter = to[0];
    char toNo = to[1];

    // Validating the letters and numbers, and checking if the move is diagonal and forward
    if(isLetterValid(fromLetter) && isNumberValid(fromNo)){
        if(isLetterValid(toLetter) && isNumberValid(toNo)){
            if(toLetter - fromLetter == 1 && toNo - fromNo == 1){// Check if the move is valid for a man (diagonal move) by comparing the difference of letters and numbers
                moveValid = true;
            }
        }
    }
    return moveValid;
}

class King: public Pieces {
    public:
        bool isMoveValid(std::string from, std:: string to);
};

bool King ::isMoveValid(std::string from, std::string to){
    bool moveValid = false;

    // Extracting the letter and number from the input strings
    char fromLetter = from[0];
    char fromNo = from[1];
    char toLetter = to[0];
    char toNo = to[1];

    // Validating the letters and numbers, and checking if the move is diagonal
    if(isLetterValid(fromLetter) && isNumberValid(fromNo)){
        if(isLetterValid(toLetter) && isNumberValid(toNo)){
            if(abs(toLetter - fromLetter) == abs(toNo - fromNo)){// Check if the move is diagonal by comparing the absolute difference of letters and numbers
                moveValid = true;
            }
        }
    }
    return moveValid;
}

int main() {
    Pieces* pieces[2];

    pieces[0] = new Man();
    pieces[1] = new King();

    std::cout << std::boolalpha; // print bool values as true or false
    std::cout << pieces[0]->isMoveValid("b1", "c2") << std::endl;
    std::cout << pieces[1]->isMoveValid("b1", "d3") << std::endl;
    std::cout << pieces[0]->isMoveValid("b1", "d3") << std::endl;

    delete pieces[0];
    delete pieces[1];

    return 0;
}