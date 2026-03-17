/*
Write a C++ program that creates a dynamic 2D array using pointers. Your program should do the following:

Ask the user to input the number of rows and number of columns.

Dynamically allocate memory for a 2D array using pointers to pointers.

Fill the array with numbers such that each element in row r and column c is calculated as:

value = r * 10 + c

Print the 2D array in a tabular format.

Free all the dynamically allocated memory before the program ends to avoid memory leaks.
*/
#include <iostream>
using namespace std;

int main(void){
    int rows, cols;

    cout << "Enter no of rows: " << endl;
    cin >> rows;

    cout << "Enter no of cols: " << endl;
    cin >> cols;

    //create array of pointers to rows
    int **ptrarr = new int *[rows];

    //create elemnts in rows
    for (int i=0; i<rows; i++){
        ptrarr[i] = new int [cols];
    }

    //fill the array with values
    for (int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            ptrarr[r][c] = r*10 + c;
        }
    }

    //print array
    for (int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            cout << ptrarr[r][c] << '\t';
        }
        cout << endl;
    }

    //free all dinammically allocated memory
    for(int i=0; i< rows; i++){
        //free each row
        delete[] ptrarr[i];
    }
    //free array of pointers
    delete[] ptrarr;
}
