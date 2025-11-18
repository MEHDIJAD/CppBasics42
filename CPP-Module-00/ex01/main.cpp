#include <iostream>
#include <sstream>

#include "PhoneBook.hpp"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
    std::string input;
    PhoneBook PhBook;
    int index;

    while (std::cout << "\e[36m🕮  \e[0m" && std::getline(std::cin, input))
    {
        size_t start = input.find_first_not_of(" \t\n\r");
        /* this evaluat to if i go thgout the howle input and not find
            " \t\n\r" return npos -> (npos == npos) true
        */
        if (start == std::string::npos){
            continue;
        }
        size_t end = input.find_last_not_of(" \t\n\r");  // we use it to trim spaces
        input = input.substr(start, end - start + 1);
        if (input == "ADD"){
            PhBook.AddContact();
        }
        else if (input == "SEARCH")
        {
            PhBook.DisplayContacts();
            if (PhBook.NumContact() > 0)
            {
                std::string lineInput;
                while (true)
                {
                    std::cout << "\e[35mEnter index: \e[0m";
                    if (!std::getline(std::cin, lineInput)) break;
                    std::stringstream st(lineInput);
                    if ((st >> index) && st.eof())
                    {
                        if (index >= 0 && index < PhBook.NumContact())
                        {
                            PhBook.OneContact(index);
                            break;
                        }
                        else
                        {
                            std::cout << "\e[31mInvalid index\e[0m"
                                      << std::endl;
                        }
                    }
                    else
                    {
                        std::cout
                            << "\033[31mInvalid index. Please try again.\033[0m"
                            << std::endl;
                    }
                }
            }
        }
        else if (input == "EXIT"){
            break;
        }
        else{
            std::cout << "\e[31m<ADD> <SEARCH> <EXIT>\e[0m" << std::endl;
        }
    }
    return (0);
}
