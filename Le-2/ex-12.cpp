/*
Create the AddToCollection function to dynamically grow a Collection by adding a new integer, 
properly reallocating memory. Test it so that elements are copied, new values appended, and old memory freed.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Collection {
	int  elno;
	int *elements;
};

void AddToCollection(Collection &col, int element) {
    
    //if elno is zero, create array with 1 element and assign value. increase elsno to 1.
    if (col.elno == 0){
        col.elements = new int[1];
        col.elements[0] = element;
        col.elno = 1;
    } else { //if not 1, create new array length of elno+1, and copy all elemnts to new array and add the new element to it.
        int *newElements;
        newElements = new int[col.elno + 1];

        //go through new array to assign value from old
        for(int i=0; i<col.elno; i++){
            newElements[i] = col.elements[i];
        }
        //add new element
        newElements[col.elno] = element;

        // free the memory of old array
        delete[] col.elements;

        //assign new array to collection 
        col.elements = newElements;

        //increase elno by 1
        col.elno++;
        
    }
}

void PrintCollection(Collection col) {
	cout << "[ ";
	for(int i = 0; i < col.elno; i++)
		cout << col.elements[i] << " ";
	cout << "]" << endl;
}

int main(void) {
	Collection collection = { 0, NULL };

	int elems;
	cout << "How many elements? ";
	cin >> elems;
	srand(time(NULL));
	for(int i = 0; i < elems; i++)
		AddToCollection(collection, rand() % 100 + 1);
	PrintCollection(collection);
	delete[] collection.elements;
	return 0;
}