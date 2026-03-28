/*
Write a program that accepts a line of text and removes any extra consecutive whitespace characters, ensuring that only a single space remains between words.

Requirements
The program should:
Read a full line of input text
Replace sequences of multiple whitespace characters (spaces, tabs, etc.) with a single space
Do not remove all spaces—only reduce duplicates
Leading and trailing spaces may be handled (trimmed) if desired
*/

#include <string>
#include <iostream>

using namespace std;

int main()
{
    std::string sentence;
    std::cout << "Enter sentence: ";
    std::getline(std::cin, sentence);
    
    size_t start_point = 0;
    size_t end_point = 0;
    while(start_point < sentence.length()){
        size_t space_point = sentence.find(" ", start_point);
        if(space_point != string::npos){
            start_point = space_point+1; // if space found, next startting point starts after there
            int i= space_point+1; //the point after the found space
            int space_count = 0; // extra space count
            while(sentence[i] == ' ' && i < sentence.length()){ // if there are more spaces, count them and move the point
                space_count++;
                i++;
            }
            
            // check if more spaces found
            if (space_count != 0){
                sentence.erase(start_point, space_count);
            }
        } else {
            break;
        }
    }

    // manipulate the sentence here

    std::cout << sentence << "\n";
    return 0;
}