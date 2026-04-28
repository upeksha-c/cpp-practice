/*
This program demonstrates inheritance and polymorphism.

A base class defines a virtual function draw().
Three derived classes override this function to print
different ASCII tree shapes.

In main(), an array of base class pointers is used
to store objects of different derived types. A loop
calls draw() for each object.

Drawing 1:
 /\
 //\\

Drawing 2:
 / \
 /**\

Drawing 3:
 / \
 /++\

*/

#include<iostream> 

class Trees{ 
    public: 
        virtual void draw(){}; 
    }; 
    
class Tree1: public Trees{ 
    public: 
        void draw(){ 
            std::cout << " /\\\n"; std::cout << "//\\\\\n"; 
        } 
}; 

class Tree2: public Trees{ 
    public: 
        void draw(){ 
            std::cout << "/ \\\n"; std::cout << "/**\\\n"; 
        } 
}; 

class Tree3: public Trees{ 
    public: 
        void draw(){ 
            std::cout << "/\\\n"; std::cout << "/++\\\n"; 
        } 
}; 

int main(){ 
    Trees* trees[3]; 
    
    trees[0] = new Tree1; 
    trees[1] = new Tree2; 
    trees[2] = new Tree3; 
    
    for(int i=0; i<3; i++){ 
        std::cout << "Drawing " << i+1 << " : \n"; 
        trees[i]->draw(); 
    } 
    
    for(int i=0; i<3; i++){ 
        delete trees[i]; 
    } 

    return 0;
}