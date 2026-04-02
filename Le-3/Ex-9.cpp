#include<iostream>
#include<string>

using namespace std;

int main(){
    string word1;
    string word2;
    
    //get input from user
    cout << "Enter 2 words: ";
    cin >> word1 >> word2;
    
    //create a copy of word2
    string word2_cpy = word2;
    
    //takeeach character in word1 and find it in the copy of word2
    for(int i=0; i<word1.length(); i++){
        int position = word2_cpy.find(word1[i]);
        //if not dount, it is not anagram
        if(position == string::npos){
            cout<< "not anagrams"<< endl;
            return 0;
        } else { //if found, remove the character from the copy of word2
            word2_cpy.erase(position, 1);
        }
        
        //if copy has length 0 it is anagram
        if(!word2_cpy.length()){
            cout<< "anagrams"<< endl;
        }
    }
    
    
}