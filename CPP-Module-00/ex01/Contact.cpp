#include "header.h"

bool Contact::SetFirstName(std::string FirstName)
{
    try
    {
        size_t i = -1;
        while (++i < FirstName.length()) {
        if (!isalpha(FirstName[i]) && FirstName[i] != '-' 
            && FirstName[i] != '_' && FirstName[i] != ' '){
            throw std::invalid_argument("\e[31mInvalid First Name\e[0m");
            // ❗ Stop execution here and jump to catch if input is invalid
                return (false);
            }
        }
            _FirstName = FirstName;
            return (true);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return (false);
    }   
}

std::string Contact::FirstName() {
    return (_FirstName);
}

bool Contact::SetLastName(std::string LastName)
{
    try
    {
        size_t i = -1;
        while (++i < LastName.length()) {
        if (!isalpha(LastName[i]) && LastName[i] != '-' 
            && LastName[i] != '_' && LastName[i] != ' '){
            throw std::invalid_argument("\e[31mInvalid Last Name\e[0m");
            // ❗ Stop execution here and jump to catch if input is invalid
                return (false);
            }
        }
            _LastName = LastName;
            return (true);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return (false);
    }   
}

std::string Contact::LastName(){
    return (_LastName);
}

void Contact::SetNickname(std::string Nickname){
    _Nickname = Nickname;
}

std::string Contact::Nickname(){
    return (_Nickname);
}

bool Contact::SetPhoneNumber(std::string PhoneNumber) {
    char current_char;
    size_t index = -1;

    while (++index < PhoneNumber.length())
    {
        current_char = PhoneNumber[index];
        if(!isdigit(current_char)){
            std::cout << "\e[31mInvalid phone number (0-9) \e[0m\n";
            return (false);
        }
    }
    _PhoneNumber = PhoneNumber;
    return (true);
}

std::string Contact::PhoneNumber(){
    return (_PhoneNumber);
}

void Contact::SetDarkestSecret(std::string DarkestSecret) {
     _DarkestSecret = DarkestSecret;
}

std::string Contact::DarkestSecret() {
    return (_DarkestSecret);
}
