/*
The program should read a single line of text (the password) and validate it according to the following rules:

1. The password must be **exactly 8 characters long**.
2. It must contain **at least one uppercase letter** (A–Z).
3. It must contain **at least one lowercase letter** (a–z).
4. It must contain **at least one digit** (0–9).
5. It must contain **at least one special character** (e.g., !, @, #, $, %, [], etc.)

If the password violates any of these rules, the program should display a message explaining each missing requirement.

Output:
- If the password meets all criteria, print:
  "The password is valid"
- If the password fails any criteria, print each specific rule that was broken on a separate line.


*/

#include <string>
#include <iostream>

int main()
{
    std::string password;
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    bool is_eight_long = false;
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;

    //check the password for each condition
    if(password.length()>=8){ //check if password is 8 characters long
        is_eight_long = true;
    }
    for(char &c: password){   
        if(isupper(c)){//check if password has upper case letter
            has_upper = true;
        } else if (islower(c)){//check if password has lower case letter
            has_lower = true;
        } else if (isdigit(c)){//check if password has digit
            has_digit = true;
        } else if (ispunct(c)){//check if password has special character
            has_special = true;
        }
    }

    //check if all conditions are met
    if(is_eight_long && has_upper && has_lower && has_digit && has_special){
        std::cout << "Password is valid." << std::endl;
    } else {
        if(!is_eight_long){
            std::cout << "The password must be 8 characters long" << std::endl;
        }
        if(!has_upper){
            std::cout << "The password must have at least one upper case letter" << std::endl;
        }
        if(!has_lower){
            std::cout << "The password must have at least one lower case letter" << std::endl;
        }
        if(!has_digit){
            std::cout << "The password must have at least one digit" << std::endl;
        }
        if(!has_special){
            std::cout << "The password must have at least one special character" << std::endl;
        }
    }
    return 0;
}