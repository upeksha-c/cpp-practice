/*
🧠 Problem: Pangram Checker

🎯 Goal:
Write a program that determines whether a given sentence is a pangram.

📌 Definition:
A pangram is a sentence that contains every letter of the English alphabet
(at least once), regardless of case.

📋 Requirements:
- Read a full line of text from the user.
- Ignore non-alphabetic characters (digits, punctuation, spaces).
- Treat uppercase and lowercase letters as the same.
- Count how many times each letter (a–z) appears.
- Determine whether all 26 letters are present at least once.

📤 Output:
- Print "Pangram" if all letters are present.
- Otherwise, print "Not pangram".
- Additionally, display each letter along with its occurrence count.

💡 Example:
Input:
"The quick brown fox jumps over the lazy dog"

Output:
Pangram
a - 1
b - 1
c - 1
...
z - 1
*/

#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

struct letter{
    char letter;
    int count;
};

int main() {
    string input;
    cout << "Enter a string: " << endl;

    getline(cin, input);
    
    bool is_pangram = true;
    
    letter letter_collection[] = {{'a',0},{'b',0},{'c',0},{'d',0},{'e',0},{'f',0},{'g',0},{'h',0},{'i',0},{'j',0},{'k',0},{'l',0},{'m',0},{'n',0},{'o',0},{'p',0},{'q',0},{'r',0},{'s',0},{'t',0},{'u',0},{'v',0},{'w',0},{'x',0},{'y',0},{'z',0}};

    // Write your code here
    for(int i=0; i<input.length(); i++){
        if(!isalpha(input[i])){
            continue;
        }
        for(int j=0; j<sizeof(letter_collection)/sizeof(letter_collection[0]); j++){
            if(input[i] == letter_collection[j].letter || tolower(input[i]) == letter_collection[j].letter){
                letter_collection[j].count ++;
                break;
            }
        }
    }
    
    
    for(int i=0; i<sizeof(letter_collection)/sizeof(letter_collection[0]); i++){
        if(!letter_collection[i].count){
            is_pangram = false;
        }
    }
    
    if(is_pangram){
        cout << "Pangram"<<endl;
    } else {
        cout << "Not pangram"<<endl;
    }
    for(int i=0; i<sizeof(letter_collection)/sizeof(letter_collection[0]); i++){
        cout <<letter_collection[i].letter << " - " << letter_collection[i].count << endl;
    }

    return 0;
}
