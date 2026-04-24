/*
    Create a class to represent fractions. The class should provide the following features:

- A textual representation of the fraction that displays:
  - Whole parts correctly (e.g., 7/4 appears as "1 3/4")
  - Signs correctly (e.g., -3/4 and 3/-4 both appear as "-3/4")
- A floating-point (decimal) representation of the fraction's value

You may assume that the denominator will never be zero.

The program should accept user input in the format: "[numerator] / [denominator]"

Sample Input 1:
3 / 4

Expected Output 1:
3/4 is 0.75 in decimal

Sample Input 2:
7 / -4

Expected Output 2:
-1 3/4 is -1.75 in decimal

Sample Input 3:
8 / 4

Expected Output 3:
2 is 2.0 in decimal

Sample Input 4:
-6 / 8

Expected Output 4:
-6/8 is -0.75 in decimal
*/




#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
private:
  int numerator;
  int denominator;
};

// implement Fraction methods
Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

string Fraction :: toString(){
    if((numerator/denominator) != 0){
        int whole = numerator/denominator;
        int num = abs(numerator % denominator);
        int den = abs(denominator);
        
        if(num == 0){
            return(std::to_string(whole));
        } else {
            return(std::to_string(whole) + " " + std::to_string(num) + "/" + std::to_string(den));
        }
    } else {
        return(std::to_string(numerator) + "/" + std::to_string(denominator));
    }
}

double Fraction::toDouble(){
    return(double(numerator)/denominator);
}

int main(void) {
  int num, den;
  char slash;
  std::string input = "";
  std::getline(std::cin,input);
  
  std::stringstream ss(input);
  ss >> num;
  ss >> slash >> den;

  if(slash != '/' || den == 0){
      std::cout << "Invalid input" << std::endl;
      return 0;
  }
  // parse input and get numerator and denominator

  Fraction fraction(num, den);

	cout << fraction.toString() << " is " <<fraction.toDouble() << " in decimal" << endl;
	return 0;
}