/*This exercise focuses on combining smaller validator components using object-oriented composition.

You should build a custom validator by putting together existing basic validation rules to form a more advanced one.

The validator must enforce the following password requirements:
- minimum length of 8 characters
- at least one uppercase letter
- at least one lowercase letter
- at least one numeric digit
- at least one special character

You can reuse earlier validator implementations if needed, but you may need to adjust or extend the pattern definitions used in PatternValidator.*/

#include <iostream>
#include <string>
#include <cctype>

class StringValidator
{
public:
  virtual ~StringValidator() {};
  virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator:public StringValidator{
    private :
        int min_length;
    public:
        MinLengthValidator(int min_length){
            this->min_length = min_length;
        }
        bool isValid(std::string input);
};

bool MinLengthValidator::isValid(std::string input){
    if(input.length() >= min_length){
        return true;
    } else {
        return false;
    }
}

class MaxLengthValidator:public StringValidator{
    private :
        int max_length;
    public:
        MaxLengthValidator(int max_length){
            this->max_length = max_length;
        }
        bool isValid(std::string input);
};

bool MaxLengthValidator::isValid(std::string input){
    if(input.length() <= max_length){
        return true;
    } else {
        return false;
    }
}

class LengthValidator : public StringValidator
{
public:
  LengthValidator(int min, int max);
  bool isValid(std::string input);
private:
  MinLengthValidator min_validator;
  MaxLengthValidator max_validator;
};

LengthValidator::LengthValidator(int min, int max):
  min_validator(min), max_validator(max)
{
}

bool LengthValidator::isValid(std::string input)
{
  return ( min_validator.isValid(input)
        && max_validator.isValid(input) );
}

class PatternValidator: public StringValidator{

    public:
        PatternValidator(){};
        bool isValid(std::string input);
};

bool PatternValidator::isValid(std::string input){
    bool upper_case = false;
    bool lower_case = false;
    bool digit = false;
    bool special_char = false;

    for(size_t i=0; i<input.length(); i++){
        if(isupper(input[i])) {
            upper_case = true;
        } else if(islower(input[i])){
            lower_case = true;
        } else if(isdigit(input[i])){
            digit = true;
        } else {
            special_char = true;
        }
    }
    return(upper_case && lower_case && digit && special_char);
}

class PasswordValidator : public StringValidator{
    private:
        LengthValidator length_validator;
        PatternValidator pattern_validator;
    public:
        PasswordValidator(int min_length, int max_length) : length_validator(min_length, max_length), pattern_validator()
        {}
        bool isValid(std::string input);
};

bool PasswordValidator::isValid(std::string input){
    return (length_validator.isValid(input) && pattern_validator.isValid(input));
}

// Your code here

using namespace std;

void printValid(StringValidator &validator, string input)
{
  cout << "The string '" << input << "' is "
       << (validator.isValid(input) ? "valid" : "invalid")<< endl;
}

int main(){
    PasswordValidator pass_validator(8,20);
    printValid(pass_validator, "aA1!"); // Invalid: too short
    printValid(pass_validator, "MyPassword123!"); // Valid
    printValid(pass_validator, "mypassword123!"); // Invalid: no uppercase letter
    printValid(pass_validator, "MYPASSWORD123!"); // Invalid: no lowercase letter
    printValid(pass_validator, "MyPassword!"); // Invalid: no digit
    printValid(pass_validator, "MyPassword123"); // Invalid: no special character
    return 0;
}