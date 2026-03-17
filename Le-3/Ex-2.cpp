/*
Task: Student Grades Summary (Dynamic 2D Arrays)

Write a C++ program to manage a student's course grades.

Requirements:
- The number of courses is given as input.
- Each course has a variable number of grades.
- Grades are integers between 1 and 5.

Program should:
1. Store all grades using a dynamic 2D structure.
2. Calculate the average grade for each course.
3. Display each course’s grades and its average.
4. Calculate and display the overall average across all courses.

Note:
- Print all averages with 2 decimal places.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
    int courses;
    
    cout << "How many courses: " << endl;
    cin >> courses;
    
    //create a array of pointers to courses
    int **arra = new int *[courses];
    int *grades = new int [courses];
    
    float finalGrade=0;
    
    for(int i=0; i<courses; i++){
        cout << "This is course " << i+1 << ", how many grades: "<< endl;
        cin >> grades[i];
        
        arra[i] = new int [grades[i]];
        
        cout<< "Enter grade: " << endl;
        for(int g=0; g<grades[i]; g++){
           cin >> arra[i][g];
        }
    }
    
    for (int i=0; i<courses; i++){
        int totalGrade = 0;
        for(int g=0; g<grades[i]; g++){
            totalGrade += arra[i][g];
        }
        finalGrade += (totalGrade/float(grades[i]));
        cout << fixed << setprecision(2);
        cout << "Course "<< i+1 << ": final " << totalGrade/float(grades[i]) << ", grades: ";
        for(int g=0; g<grades[i]; g++){
            cout << arra[i][g] << " ";
        }
        cout << endl;
    }
    float overallGrade =  finalGrade/courses;
    cout << fixed << setprecision(2);
    cout << "Overall final "<< overallGrade << endl;
    
    
}