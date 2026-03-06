/*Write a C++ program that finds the smallest element in a vector using pointers only*/

#include <iostream> 

using namespace std; 

int main(void) { 
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 }; 
    int n = sizeof(vector) / sizeof(vector[0]); 
    int *smallest; smallest = vector; 
    
    // Insert your code here 
    for(int i = 0; i<n; i++){ 
        if(*(vector+i)< *smallest ){ 
            smallest = vector+i; 
        } 
    } 
    cout << "smallest = " << *smallest << endl; 
    return 0; 
}