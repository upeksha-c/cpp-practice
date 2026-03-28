/*
Write a program that reads a line of text and removes immediately repeated words, keeping only the first occurrence.

Rules
Words are considered duplicates only if they appear consecutively and are exactly the same.
If two identical words are separated by punctuation (such as commas), they should NOT be treated as duplicates.
The program should preserve the original structure of the sentence as much as possible.
*/

#include <string>
#include <iostream>

using namespace std;

int main()
{
    // Read a line of text from the user
    std::string sentence;
    cout << "Enter the sentence: ";
    std::getline(std::cin, sentence);

    size_t start_point = 0;// Starting point for searching words
    
    size_t end_point = sentence.find(" ", start_point);// Ending point for the first word                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    string first_word = sentence.substr(start_point,(end_point-start_point));  // Extract the first word from the sentence
    
    while(end_point != string:: npos) {
        size_t temp_start = start_point;// Store the current starting point before moving to the next word
        size_t temp_end = end_point;// Store the current ending point before moving to the next word
        
        start_point = end_point+1; // Move the starting point to the beginning of the next word
        end_point = sentence.find(" ", start_point); // Find the ending point of the next word
        string second_word = sentence.substr(start_point,(end_point-start_point)); // Extract the next word from the sentence
        
        //compare word1 and 2, if same remove the 2nd word
        if(first_word == second_word){
          sentence.erase(start_point,(end_point-start_point)+1);  
          start_point = temp_start; // Move the starting point back to the first word
          end_point = temp_end; // Move the ending point back to the first word
        } else{
           first_word = second_word; // make the second word the first word for the next loop
        }              
    }
    std::cout << sentence << "\n";
}