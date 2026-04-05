/*
    Implement a class called AdHocSquare that calculates the area of a 
    square whenever the get_area method is called. 
    Then, implement another class called LazySquare that calculates the 
    area only when the side length changes and stores the result for future use. 
    Compare the performance of both classes by creating instances and calling their 
    get_area methods multiple times.
*/

#include<iostream>
// create AdHocSquare class with private and public members
class AdHocSquare
{
    public:
        AdHocSquare(double side);
        void set_side(double side);
        double get_area();
    private:
        double side;
};

// build AdHocSquare constructor 
AdHocSquare ::AdHocSquare(double side){
    if(side>0){
        this->side = side;
    }
}

// build AdHocSquare set_side method to update the side of the square
void AdHocSquare :: set_side(double side){
    this->side = side;
}

// build AdHocSquare get_area method to calculate the area of the square
double AdHocSquare :: get_area(){
    return side*side;
}


// create LazySquare class with private and public members
class LazySquare
{
    public:
        LazySquare(double side);
        void set_side(double side);
        double get_area();
    private:
        double    side;
        double    area;
        bool side_changed;
};

// build LazySquare constructor
LazySquare :: LazySquare(double side){
    if(side>0){
        this->side = side;
        area = side*side;
        side_changed = false;
    }    
}

// build LazySquare set_side method to update the side of the square and mark the area as changed
void LazySquare :: set_side(double side){
    if(side>0){
        this->side = side;
        side_changed = true;
    }
}

// build LazySquare get_area method to calculate the area of the square only if the side has changed
double LazySquare :: get_area(){
    if(side_changed){
        area = side*side;
        side_changed = false;
    } 
    return area;
    
}

int main(){
    AdHocSquare squ1(5);
    std::cout << "AdHocSquare area: " << squ1.get_area() << std::endl;

    LazySquare squ2(10);
    std::cout << "LazySquare area: " << squ2.get_area() << std::endl;

    squ1.set_side(7);
    std::cout << "AdHocSquare area after changing side: " << squ1.get_area() << std::endl;

    squ2.set_side(15);
    std::cout << "LazySquare area after changing side: " << squ2.get_area() << std::endl;
    return 0;
}