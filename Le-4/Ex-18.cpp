#include <iostream>
#include <string>

class StringValidator
{
public:
  virtual ~StringValidator() {};
  virtual bool isValid(std::string input) = 0;
};

// Write your code here

class DummyValidator : public StringValidator {
public:
  virtual bool isValid(std::string input);
};

bool DummyValidator::isValid(std::string input)
{
  return true;
}


class ExactValidator: public StringValidator{
    private:
        std::string secrete;
    public:
        ExactValidator(std::string secrete){
            this->secrete = secrete;
        }
        ~ExactValidator(){};
        bool isValid(std::string input);
};

bool ExactValidator::isValid(std::string input){
    if(input == secrete){
        return true;
    } else {
        return false;
    }
}
using namespace std;

void printValid(StringValidator &validator, std::string input)
{
  cout << "The string '" << input << "' is "
       << (validator.isValid(input) ? "valid" : "invalid")<< endl;
}


int main()
{
  DummyValidator dummy;
  printValid(dummy, "hello");
  cout << endl;

  ExactValidator exact("secret");
  printValid(exact, "hello");
  printValid(exact, "secret");
  return 0;
}