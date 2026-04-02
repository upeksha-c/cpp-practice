/*
Create a function that takes a string as input and determines whether it represents a valid IPv4 address.

The function should analyze the string and return a message describing the result.

Validation rules:
The address must consist of four numeric sections separated by dots (.).
Each section must:
Contain only digits
Have a value between 0 and 255
Not be excessively long (e.g., more than 3 digits)
The input must not contain any characters other than digits and dots.

Possible return messages:
"Valid IP address"
"Invalid: too many sections"
"Invalid: incorrect number of sections"
"Invalid: non-numeric characters detected"
"Invalid: section value exceeds 255"
"Invalid: section too long"
*/

#include<iostream>
#include<string>
using namespace std;

int main(void){
    string ip;
    cout << "Enter IP address: ";
    getline(cin, ip);
    
    //if ip address is long than needed 
    if(ip.length() > 15){
        cout << "Incorrect parts count." << endl;
        return 0;
    }
    
    //if ip address has more than 3 periods
    int period_count = 0;
    int period;
    int start_point = 0;
    
    do{
        period = ip.find(".", start_point);
        if(period != string::npos){
            period_count++;
            start_point = period+1;
        }
    } while(period != string::npos);
    
    if(period_count != 3){
        cout << "Invalid IP address" << endl;
        return 0;
    }
    
    //devide ip into 4 parts by period
    string period_array[period_count+1] = {};
    int period1 =0;
    for (int i=0; i<period_count+1; i++){
        int period2 = ip.find(".", period1);
        period_array[i]= ip.substr(period1,period2-period1);
        period1 = period2+1;

        //check if each part has characters other than digit
        for(int j=0; j<period_array[i].length(); j++){
            if(!isdigit(period_array[i][j])){//isdigit used to check if a character is a digit
                cout << "Only digits and dots allowed" << endl;
                return 0;
            }
        }
        if(period_array[i].length() > 3){
            cout << "Too many characters in a part" << endl;
            return 0;
        } else if(stoi(period_array[i]) > 255){
            cout << "Too big a value of a part" << endl;
            return 0;
        } else if(stoi(period_array[i]) < 0){ //stoi used to convert string to int
            cout << "Negative value of a part" << endl;
            return 0;
        }
    }

    cout << "Correct IP" << endl;
}