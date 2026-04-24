#include<iostream>
#include<string>

using namespace std;

int main(){
    string word ="Learning ";
    
    word.append("C++");
    word.append(9,"modern ");
    
    cout << word;
    
    
    return 0;
}