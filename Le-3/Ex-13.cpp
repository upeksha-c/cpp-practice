/*
1. Read **two lines of input**:
   - **Line 1:** A list of key=value pairs separated by commas (e.g., "name=Alice,task=clean the room").
   - **Line 2:** A template message containing placeholders in the form "[key]".
2. Replace each placeholder in the template with the corresponding value from the key-value pairs.
3. If a placeholder has no matching key, leave it unchanged in the output.
4. Preserve all other text exactly as it appears.

Output:
- Print the resulting message after all replacements.

Examples:

Input:
person=Paul,action=strolls around,place=the park
[person] [action] [place]

Output:
Paul strolls around the park

---

Input:
customer=John,pet=dog
Dear [customer], we were happy to take care of your [pet] while you were away. Please call our pet hotel again if you need help with your [pet]!

Output:
Dear John, we were happy to take care of your dog while you were away. Please call our pet hotel again if you need help with your dog!

*/

#include <string>
#include <iostream>

int main()
{
    std::string values;
    std::getline(std::cin, values);

    std::string templates;
    std::getline(std::cin, templates);

    std::size_t begining = 0;
    std::size_t ending = 0;

    do{
        //find comma to extract each value
        ending = values.find(',', begining);
        std::string name_value;
        if(ending != std::string::npos){
            name_value = values.substr(begining, ending-begining);//if there is a comma, extract the value until the nextcomma
        } else {
            name_value = values.substr(begining);//if there is no more comma, extract the last value
        }

        //find name and value by finding the equal sign
        std::size_t equal_sign = name_value.find('=');
        std::string name = name_value.substr(0, equal_sign);
        std::string value = name_value.substr(equal_sign+1);

        //check if name exists in the template and replace it with the value
        std:: string checking_word = "[" + name + "]";
        std:: size_t word_start_point;
        word_start_point =  templates.find(checking_word);

        while(word_start_point != std::string::npos){
            word_start_point =  templates.find(checking_word);
            if(word_start_point != std::string::npos){
                //replace name with it's value
                templates.replace(word_start_point,checking_word.length(),value);
            }
        }

        //assign the begining point to the next value
        begining = ending+1;


    }while(ending != std::string::npos);

    std::cout << templates << "\n";
}