/*
Write a program that:

Reads two lines of input:
Line 1: A pattern
Line 2: A block of text
Searches the text and prints all substrings that match the given pattern.

Pattern Rules
A pattern is made up of non-space characters.
Each character in the pattern has a specific meaning:
D → matches any digit (0–9)
Example: DDDD matches 1234, 9087
A → matches any letter (a–z, A–Z)
Example: AAA matches cat, DOG, Mix
Lowercase letters (a–z) → match the same letter, case-insensitive
Example: cat matches cat, CAT, Cat
? → matches any single character, including spaces
Other characters (e.g., -, ,, etc.) → must match exactly
*/

#include <string>
#include <iostream>

int main()
{
    std::string pattern;
    std::getline(std::cin, pattern);

    std::string sentence;
    std::getline(std::cin, sentence);
    
    std::size_t begining = 0;
    std::size_t ending = 0;

    do {
        //find next space
        ending = sentence.find(' ', begining);

        //get word length
        std::size_t word_length = 0;
        if(ending == std::string::npos){
            word_length = sentence.length()-begining;
        } else {
            word_length = ending - begining;
        }

        //extract the word
        std::string word = sentence.substr(begining,word_length);
        //remove trailing period and comma if exist
        while(!word.empty() && (word.back() == '.' || word.back() == ',')){
            word.pop_back();
            word_length = word.length();
        }

        //get pattern length
        std::size_t pattern_length = pattern.length();

        //check if pattern and selected word lenth equal. if not continue to next word.if so check next needs.
        if(pattern_length != word_length){
            if(ending == std::string::npos){ //if there is no more space, break the loop
                break;
            }   
            begining = ending+1;//move the begining point to the next word and continue to next loop
            continue;
        }

        int match_count = 0; 

        //check each character in the word with the pattern
        for(int i=0; i<pattern_length; i++){
            bool does_match = false; //flag to check if the character matches the pattern
            if(pattern[i] == 'D'){
                does_match = isdigit(word[i]);
            } else if(pattern[i] == 'A'){
                does_match = isalpha(word[i]);
            } else if(pattern[i]>='a' && pattern[i]<='z'){
                if(pattern[i] == word[i] || pattern[i] == toupper(word[i])){
                    does_match = true;
                }
            } else if(pattern[i] == '?'){
                if(ispunct(word[i]) || isspace(word[i])){
                    does_match = true;
                }
            }else {
                if(word[i] == pattern[i]){
                    does_match = true;
                }
            }

            
            if(!does_match){//if any character does not match the pattern, break the loop and continue to next word
                break;
            } else {//if the character matches the pattern, increase the match count
                match_count++;
            }
        }

        //if all characters match the pattern, print the word
        if(match_count == pattern_length){
            std::cout << word << "\n";
        }

        //if there is no more space, break the loop and if not move the begining point to the next word
        if(ending != std::string::npos){
            begining = ending+1;
        } else {
            break;
        }
    } while(ending != std::string::npos);

    std::cout << sentence << "\n";
}