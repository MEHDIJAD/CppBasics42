#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

/* 1. Default Constructor */
PhoneBook::PhoneBook() : _NumContacts(0), _nextIndex(0)
{
    /* Empty */
}

/* 2. Copy Constructor */
PhoneBook::PhoneBook(const PhoneBook &other)
{
    *this = other;
}

/* 3. Copy Assignment Operator */
PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
    if (this != &other)
    {
        this->_NumContacts = other._NumContacts;
        this->_nextIndex = other._nextIndex;

        for (int i = 0; i < 3; i++)
        {
            this->_Contacts[i] = other._Contacts[i];
        }
    }
    return *this;
}


void PhoneBook::AddContact()
{
    Contact newContact;
    std::string Input;

    while (true)
    {
        std::cout << "\e[33mEnter First name: \e[0m";
        if (!std::getline(std::cin >> std::ws, Input)){
            return;
        }
        if (newContact.SetFirstName(Input)){
            break;
        }
    }

    while (true)
    {
        std::cout << "\e[33mEnter Last name: \e[0m";
        if (!std::getline(std::cin >> std::ws, Input)){
            return;
        }
        if (newContact.SetLastName(Input)){
            break;
        }
    }

    while (true)
    {
        std::cout << "\e[33mEnter Nickname: \e[0m";
        if (!std::getline(std::cin >> std::ws, Input)){
            return;
        }
        if (newContact.SetNickname(Input)){
            break;
        }
    }
    while (true)
    {
        std::cout << "\e[33mEnter Phone Number: \e[0m";
        if (!std::getline(std::cin >> std::ws, Input)){
            return;
        }
        if (newContact.SetPhoneNumber(Input)){
            break;
        }
    }

    while (true)
    {
        std::cout << "\e[33mWhat is your Darkest Secret: \e[0m";
        if (!std::getline(std::cin >> std::ws, Input)){
            return;
        }
        if (newContact.SetDarkestSecret(Input)){
            break;
        }
    }
    _Contacts[_nextIndex] = newContact;

    if (_NumContacts < 3)
    {
        _NumContacts++;
    }
    _nextIndex = (_nextIndex + 1) % 3;
}

std::string truncate_string(const std::string &str, size_t width)
{
    if (str.length() > width){
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

void PhoneBook::DisplayContacts()
{
    if (_NumContacts == 0)
    {
        std::cout << "\e[36mPhoneBook is empty. No contacts to display.\e[0m"
                  << std::endl;
        return;
    }

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    int i = 0;

    while (i < _NumContacts)
    {
        std::cout << "|" << std::right << std::setw(10) << i;
        std::cout << "|" << std::right << std::setw(10)
                  << truncate_string(_Contacts[i].FirstName(), 10);
        std::cout << "|" << std::right << std::setw(10)
                  << truncate_string(_Contacts[i].LastName(), 10);
        std::cout << "|" << std::right << std::setw(10)
                  << truncate_string(_Contacts[i].Nickname(), 10);
        std::cout << "|" << std::endl;

        i++;
    }
    std::cout << "--------------------------------------------" << std::endl;
}

int PhoneBook::NumContact() const{
    return (_NumContacts);
}

void PhoneBook::OneContact(int index)
{
    if (index < _NumContacts)
    {
        std::cout << "\n";
        // std::cout << "--------------------------------------------" <<
        // std::endl;
        std::cout << "\e[32mFirst Name:     \e[0m"
                  << _Contacts[index].FirstName() << std::endl;
        std::cout << "\e[32mLast Name:      \e[0m"
                  << _Contacts[index].LastName() << std::endl;
        std::cout << "\e[32mNickname:       \e[0m"
                  << _Contacts[index].Nickname() << std::endl;
        std::cout << "\e[32mPhone Number:   \e[0m"
                  << _Contacts[index].PhoneNumber() << std::endl;
        std::cout << "\e[32mDarkest Secret: \e[0m"
                  << _Contacts[index].DarkestSecret() << std::endl;
        // std::cout << "--------------------------------------------" <<
        // std::endl;
        std::cout << "\n";
    }
    else
    {
        std::cout << "\e[31mError: The index you entered is out of range.\e[0m"
                  << std::endl;
    }
}

/* 4. Destructor */
PhoneBook::~PhoneBook() {
}
