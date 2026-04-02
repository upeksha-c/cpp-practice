/*
Write a program that reads a line of text and transforms it based on special formatting symbols.

Formatting Rules

Your program should process the text using the following rules:

Asterisk formatting (*)
Text enclosed between matching * symbols should:
Be converted to uppercase
Have the * symbols removed
Example:
this is *cool* → this is COOL
Underscore formatting (_)
Text enclosed between matching _ symbols should:
Have each character separated by a space
Replace the _ symbols with spaces
Example:
is _this_ working → is t h i s working
Unmatched symbols
If a * or _ does not have a matching closing symbol, it should be ignored.
Conflicting symbols
If an underscore section starts while inside an asterisk section (or vice versa), the inner symbol should be ignored until the outer one is closed.

Examples

Input:

What do you *mean*?

Output:

What do you MEAN?

Input:

This is _really_ important!

Output:

This is r e a l l y important!

Input:

*This* one _might *be _quite tricky_*, if you know what I mean.

Output:

THIS one might be q u i t e t r i c k y , if you know what I mean.
*/


#include <string>
#include <iostream>

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

    bool under_score_found = false;
    bool asterisk_found = false;
    int found_index = 0;

    for(int i=0; i<sentence.length(); i++){
        if(sentence[i] == '*'){
            if(under_score_found == false && asterisk_found == true){
                //extract the word between the two asterisks 
                std::string word = sentence.substr(found_index+1, i-found_index-1);
                //convert the word to uppercase
                for(char &c : word){
                    c = toupper(c);
                }
                //replace the word in the sentence with the uppercase word
                sentence.replace(found_index+1, word.length(), word);
                //erase the asterisks
                sentence.erase(found_index, 1);
                sentence.erase(i-1, 1);//decrease the index by 1 because the first asterisk is removed
                //reset the flags and found index
                asterisk_found = false;
                found_index = 0;
                i = i-2; 
            } else if(under_score_found == true && asterisk_found == false){
                //reset the underscore found flag
                under_score_found = false;
                //remove the underscore
                sentence.erase(found_index, 1);
                //flag the asterisk found
                asterisk_found = true;
                //assign index of the found asterisk to found index
                found_index = i-1;
            } else {
                //mark as asterisk found 
                asterisk_found = true;
                //assign index of the found asterisk to found index
                found_index = i;
            }                
        } else if(sentence[i] == '_'){
            if(under_score_found == true && asterisk_found == false){
                //extract the word between the two underscores
                std::string word = sentence.substr(found_index+1, i-found_index-1);
                std::string word_cpy = ""; 
                for(int j=0; j<word.length(); j++){
                    if(j != word.length()-1){
                        word_cpy += word[j];
                        word_cpy += " ";
                    } else {
                        word_cpy += word[j];
                    }
                }
                //replace the word in the sentence with the spaced word
                sentence.replace(found_index+1, word.length(), word_cpy);
                //remove the underscores
                sentence.erase(found_index, 1);
                sentence.erase(found_index+word_cpy.length(), 1);
                i = i-2;
                
                //reset the flags
                under_score_found = false;
                found_index = 0;
            }else if(under_score_found == false && asterisk_found == true){
                //reset the asterisk found flag
                asterisk_found = false;
                //remove the asterisk
                sentence.erase(found_index, 1);
                //flag the underscore found
                under_score_found = true;
                //assign index of the found underscore to found index
                found_index = i-1;
            } else {
                //mark as underscore found 
                under_score_found = true;
                //assign index of the found underscore to found index
                found_index = i;
            }
        }

        //if it is the last character and there is an unclosed asterisk or underscore, remove it
        if(i == sentence.length()-1){
            if(under_score_found || asterisk_found){
                sentence.erase(found_index, 1);
            }
        }
    }

    
    
    
    std::cout << sentence << "\n";
}