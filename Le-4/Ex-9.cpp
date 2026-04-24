/*
    A point in two-dimensional space is defined by its x and y coordinates. The distance between two points can be found using the Pythagorean theorem.

Write a program that reads two sets of coordinates (one set for each point) and calculates the Euclidean distance between them.

Sample Input 1:
0 0
3 4

Expected Output 1:
5

Sample Input 2:
9, 16
4, 4

Expected Output 2:
13

Sample Input 3:
-3 -6.7
-8.5 9

Expected Output 3:
16.6355042
*/


#include <iostream>
#include <cmath>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double toDouble();
  // ...
  double distanceTo(Point2D that);
private:
  double x;
  double y;
};

Point2D::Point2D(double x, double y){
    this->x = x;
    this->y = y;
}

double Point2D::distanceTo(Point2D that){
    double result =pow((pow((that.y - this->y),2) + pow((that.x-this->x),2)), 0.5);
    return result;
}
// implement Point2D methods
int main(){
    Point2D A(-3,-6.7);
    Point2D B(-8.5,9);
    
    std::cout << A.distanceTo(B) <<std::endl;
    return 0;
}