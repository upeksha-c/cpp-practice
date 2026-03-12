/*Write a C++ program that simulates a lottery by generating 
unique random numbers based on the total balls and number of draws.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
	int maxball;
	int ballsno;

	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	srand(time(NULL));

    //create a dynamic array to hold the drawn balls
	int *ballBox = new int[ballsno];
	
	//draw balls
	for(int i=0; i<ballsno; i++) {
        int rnd = rand() % maxball + 1;
        bool doesExist = false;
        
        //check that ball already exists
        for(int j=0; j<i; j++){
            if(ballBox[j]==rnd){
                doesExist = true;
                break;
            }
        }
        
        //if exists do the same draw again else put the ball to box
        if(doesExist){
            i--;
        } else{
            ballBox[i] = rnd;
        }
        
	}
	
	//print the balls in box
	for(int k=0; k<ballsno; k++){
	    cout<<ballBox[k]<<" ";
	}

    //free the memory
    delete[] ballBox;

	return 0;
}