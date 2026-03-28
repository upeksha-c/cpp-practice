/*
Write a program that:

Reads three lines of input:
Line 1: The text or phrase to be replaced
Line 2: The replacement text or phrase
Line 3: The main sentence or paragraph where the replacement will occur
Replaces all occurrences of the first line’s text in the third line with the text from the second line.
Ensures that overlapping or similar phrases do not break the replacement.

Rules
The program should handle multi-word phrases.
Only exact matches of the first line should be replaced.
Preserve the rest of the text exactly as it appears.

Examples

Input:

John
Mary
John had a little lamb

Output:

Mary had a little lamb
*/

#include <string>
#include <iostream>

using namespace std;

int main()
{
    std::string from;
    cout << "Enter first line:";
    std::getline(std::cin, from);

    std::string to;
    cout << "Enter second line:";
    std::getline(std::cin, to);

    std::string sentence;
    cout << "Enter third line:";
    std::getline(std::cin, sentence);

    //find string 1 length
    size_t str1_length = from.length();
    
    //find if string1 exists in 3rd string
    size_t starting_point = sentence.find(from);
    // if string exists, replace it with string2
    if(starting_point != string:: npos){
        sentence.replace(starting_point, str1_length, to);
    }
    

    std::cout << sentence << "\n";
}