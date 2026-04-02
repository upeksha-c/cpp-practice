/*
Write a program that:

Reads two lines of input:
Line 1: A list of words to ignore (separated by commas)
Line 2: A sentence or phrase to process
Removes all occurrences of the listed words from the sentence.

Rules
The words to ignore (stop words) are given in lowercase.
Matching should be case-insensitive (e.g., "This" matches "this").
Only whole words should be removed (not parts of words).
The output should contain the remaining words in their original order.
*/

#include <string>
#include <iostream>

using namespace std;

int main(){
    // Read stop words and sentence from the user
    std::string stop_words;
    cout << "Enter stop words : ";
    std::getline(std::cin, stop_words);

    std::string sentence;
    cout << "Enter sentence : ";
    std::getline(std::cin, sentence);
    
    //find each stop word in the sentence and remove it
    size_t begining = 0;
    size_t ending;
    do{
        ending = stop_words.find(',', begining);//find the comma to extract each stop word
        string s_word = stop_words.substr(begining, (ending-begining));//extract the stop word

        //find the extracted word inside the sentence
        size_t wsp; //word starting point
        size_t s_word_length = s_word.length(); //find the length of the stop word
        string sentence2 = sentence; //create a copy of the sentence

        //make sentence2 lowercase
        for(char &c : sentence2){
            c= tolower(c);
        }

        //find the word until it find nothing
        do{
            wsp = sentence2.find(s_word);//find the stop word in the sentence
            //erase the word if found
            if(wsp != string:: npos){ 
                if(wsp+s_word_length < sentence2.length() && sentence2[wsp+s_word_length] == ' '){ //check if the stop word is followed by a space
                    sentence2.erase(wsp, s_word_length+1);
                    sentence.erase(wsp, s_word_length+1);
                } else {
                    sentence2.erase(wsp, s_word_length);
                    sentence.erase(wsp, s_word_length);
                }
            }
        } while(wsp != string:: npos);
        
        begining = ending+1; //move the begining point to the next stop word
    } while (ending != string :: npos);

    std::cout << sentence<< "\n";
    return 0;
}