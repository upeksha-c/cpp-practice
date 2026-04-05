/*
    Make the area and side attributes of the Square class private.
    Add a public method called set_side that updates both side and area.
    Ensure that set_side does nothing if a negative value is passed.
    Convert the existing print function into a public method of the Square class so it can display the square’s information.
*/

#include <iostream>
#include <string>

using namespace std;

class Square
{
    // private members of the class
    private:
    double    side;
    double    area;
    
    // public members of the class
    public:
        Square(double side);    //constructor to initialize the side and area of the square
        
        //setter and getter for the side and area of the square
        void set_side(double side){
            if(side>0){
                this->side = side;
                this->area = side*side;
            } else {
                std::cout << "Invalid side value" << std::endl;
                this->side = 0;
                this->area = 0;
            }
        } 
        
        double get_side(){
            return side;
        }
        double get_area(){
            return area;
        }

        //function to print the side and area of the square
        void print(){
            cout << "Square: side=" << side << " area=" << area << endl;
        }
};

//constructor to initialize the side and area of the square
Square::Square(double side)
{
    if(side>0){
        this->side = side;
        this->area = side * side;
    } else{
        std::cout << "Invalid side value" << std::endl;
        this->side = 0;
        this->area = 0;
    }
  
}


int main()
{
  Square s(4);


  s.print();

  s.set_side(2.0);
  s.print();

  s.set_side(-33.0);
  s.print();

  return 0;
}