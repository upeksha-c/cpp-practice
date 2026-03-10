/*// Write a C++ function named increment that increases a 
variable by 1 or by a given value using pass-by-reference.*/

#include <iostream>

using namespace std;

void increment(int & variable, int expression = 1){
    for(int i=0; i< expression; i++){
        variable++;
    }
}
int main(void) {
	int var = 0;
	for(int i = 0; i < 10; i++)
		if(i % 2)
			increment(var);
		else
			increment(var,i);
	cout << var << endl;
	return 0;
}