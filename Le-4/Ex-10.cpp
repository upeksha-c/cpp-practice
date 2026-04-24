/*
    A line in two-dimensional space can be described using two parameters: the slope (a) and the y-intercept (b). Any point (x, y) lying on the line satisfies the equation y = ax + b.

Given two points that lie on a line, you can calculate both the slope and the y-intercept.

Write a program that reads two sets of x and y coordinates (one set for each point) and creates an object of a class named Line2D based on these two points. Then output the equation of the line in the format:

y = [slope]x [+ or -] [y_intercept]

Sample Input 1:
0 0
3 6

Expected Output 1:
y = 2x + 0

Sample Input 2:
2 2
-2 0

Expected Output 2:
y = 0.5x + 1

Sample Input 3:
-1 1
2 -4

Expected Output 3:
y = -1.66667x - 0.666667
*/

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double getX(){ return x; }
  double getY(){ return y; }
  // ...
private:
  double x;
  double y;
};

Point2D::Point2D(double x, double y){
    this->x = x;
    this->y = y;
}

class Line2D{
public:
  Line2D(double slope, double y_intercept);
  Line2D(Point2D pointA, Point2D pointB);
  string toString();
  // ...
private:
  double slope;
  double y_intercept;
};

Line2D::Line2D(double slope, double y_intercept){
    this->slope = slope;
    this->y_intercept = y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB){
    this->slope = (pointB.getY() - pointA.getY())/(pointB.getX() - pointA.getX());
    this->y_intercept = pointA.getY() - slope*pointA.getX();
}

string Line2D::toString(){
    std::ostringstream os;
    os << "y= ";

    if(slope == 0){
        os << y_intercept;
    } else {
        if(slope == 1){
            os << "x";
        } else if( slope == -1){
            os << "-x";
        } else {
            os << slope << "x";
        }

        if(y_intercept > 0){
            os << " + " << y_intercept;
        } else if(y_intercept < 0){
            os << " - " << fabs(y_intercept);
        }
    }

    return os.str();
}
// implement Point2D and Line2D methods

int main(){
    Point2D A(2,2);
    Point2D B(-2,0);
    
    //Line2D line1(2,3);
    Line2D line2(A,B);
    
    //std::cout << line1.toString() << std::endl;
    std::cout << line2.toString() << std::endl;
    
    return 0;
}