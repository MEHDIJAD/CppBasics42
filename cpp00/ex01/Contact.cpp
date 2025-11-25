#include "Contact.hpp"
#include <iostream> 
#include <cctype>

/* 1. Default Constructor */
Contact::Contact() : _FirstName(""), _LastName(""), _Nickname("")
    , _PhoneNumber(""), _DarkestSecret("") {

}

/* 1.1 Parameterized Constructor */
    // we do not have this becouse we input from the user

/* 2. Copy Constructor */
Contact::Contact(const Contact& other) {
    *this = other; // we want to cpy  Construct from other Object
    // so the *this Operster will take all and give it to other
}

/* 3. Copy Assignment Operator */
Contact& Contact::operator=(const Contact& other) {
    if (this != &other)
    {
        this->_FirstName = other._FirstName;
        this->_LastName = other._LastName;
        this->_Nickname = other._Nickname;
        this->_PhoneNumber = other._PhoneNumber;
        this->_DarkestSecret = other._DarkestSecret;
    }
    return *this;
}

inline bool isValid(char c){
    return ((isalpha(c) || c == '-' || c == '_'  || c == ' ') && isprint(c));
}

bool Contact::SetFirstName(std::string FirstName)
{
    size_t i = -1;
    while (++i < FirstName.length()) {
        if (!isValid(FirstName[i])){
            std::cerr << "\e[31mInvalid First Name\e[0m" << std::endl;
            return (false);
        }
    }
    _FirstName = FirstName;
    return (true);
}

std::string Contact::FirstName() {
    return (_FirstName);
}


bool Contact::SetLastName(std::string LastName)
{
    size_t i = -1;
    while (++i < LastName.length()) {
        if (!isValid(LastName[i])){
            std::cerr << "\e[31mInvalid Last Name\e[0m" << std::endl;
            return (false);
        }
    }
    _LastName = LastName;
    return (true);
}

std::string Contact::LastName(){
    return (_LastName);
}

bool Contact::SetNickname(std::string Nickname){
    return (_Nickname = Nickname, true);
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
            std::cout << "\e[31mInvalid Phone Number (0-9) \e[0m\n";
            return (false);
        }
    }
    _PhoneNumber = PhoneNumber;
    return (true);
}

std::string Contact::PhoneNumber(){
    return (_PhoneNumber);
}

bool Contact::SetDarkestSecret(std::string DarkestSecret) {
    _DarkestSecret = DarkestSecret;
    return (true);
}

std::string Contact::DarkestSecret() {
    return (_DarkestSecret);
}

Contact::~Contact() {
    // This can be empty
}
