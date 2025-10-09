#include "header.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
    std::string input;
    PhoneBook PhBook;
    int index;
    

    // std::getline returns the stream, which evaluates to `true` on success
    // and `false` on failure (like Ctrl+D), autom`atically breaking the loop.
    
    while (std::cout << "\e[36m🗒️ ~ \e[0m"
        && std::getline(std::cin, input))
    {
        // `find_first_not_of(" \t\n\r")` checks if there are any non-whitespace characters.
        // `std::string::npos` means "not found".
        if (input.find_first_not_of(" \t\n\r") == std::string::npos){
            // If the line was empty or just spaces, just loop again.
            continue;
        }
        else if (input == "ADD"){
            PhBook.AddContact();
        }
        else if (input == "SEARCH"){
            PhBook.DisplayContacts();
            if (PhBook.getNumContact() > 0)
            {
                std::string lineInput;
                while (true)
                {  
                    std::cout << "\e[35mEnter index: \e[0m";
                    if (!std::getline(std::cin, lineInput))
                        break ;
                    std::stringstream st(lineInput);
                    if ((st >> index) && st.eof()){
                        if (index >= 0 && index < PhBook.getNumContact())
                        {
                            PhBook.OneContact(index);
                            break;
                        }
                        else {
                            std::cout << "\e[31mInvalid index\e[0m" << std::endl;
                        }
                    }
                    else {
                        std::cout << "\033[31mInvalid index. Please try again.\033[0m" << std::endl;      
                    }
                }
            }
        }
        else if (input == "EXIT"){
            break ;
        }
        else {
            std::cout << "\e[31mUsage: <ADD>, <SEARCH> OR <EXIT>\e[0m" 
            << std::endl;
        }
    }
    return (0);
}
