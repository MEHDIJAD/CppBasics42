#include "header.h"

PhoneBook::PhoneBook() : _numContacts(0), _nextIndex(0){

}

void PhoneBook::AddContact(/*Contact &contacts*/)
{
    Contact newContact;
    std::string Input;

    while (true)
    {
        std::cout << "\e[33mEnter First name: \e[0m";
        if(!std::getline(std::cin >> std::ws, Input)){
            return ;
        }
        if (newContact.SetFirstName(Input))
            break;
    }
    
   while (true)
   {
         std::cout << "\e[33mEnter Last name: \e[0m";
        if (!std::getline(std::cin, Input)){
            return ;
        }
        if(newContact.SetLastName(Input)){
            break;
        }
   }

    std::cout << "\e[33mEnter Nickname: \e[0m";
    if (!std::getline(std::cin, Input)){
        return ;
    }
    newContact.SetNickname(Input);

    while (true)
    {
        std::cout << "\e[33mEnter Phone Number: \e[0m";
        if (!std::getline(std::cin, Input)){
            return ;
        }
        if (newContact.SetPhoneNumber(Input)){
            break;
    }
    
    }
    
    std::cout << "\e[33mWhat is your Darkest Secret: \e[0m";
    if (!std::getline(std::cin, Input)){
        return ;
    }
    newContact.SetDarkestSecret(Input); 
    
    _contacts[_nextIndex] = newContact;

    if (_numContacts < 8){
        _numContacts++;
    }
    _nextIndex = (_nextIndex + 1) % 8; 
}

std::string truncate_string(const std::string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

void PhoneBook::DisplayContacts()
{
    if (_numContacts == 0){
        std::cout << "\e[36mPhoneBook is empty. No contacts to display.\e[0m" << std::endl;
        return ;
    }

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    int i = 0;
    
    while (i < _numContacts)
    {
        std::cout << "|" << std::right << std::setw(10) << i;
        std::cout << "|" << std::right << std::setw(10)  << truncate_string(_contacts[i].FirstName(), 10);
        std::cout << "|" << std::right << std::setw(10) << truncate_string(_contacts[i].LastName(), 10);
        std::cout << "|" << std::right << std::setw(10) << truncate_string(_contacts[i].Nickname(), 10);
        std::cout << "|" << std::endl;

        i++;
    }
    std::cout << "--------------------------------------------" << std::endl;

}


int PhoneBook::getNumContact() const {
    return (_numContacts);
}

void PhoneBook::OneContact(int index)
{
    if (index < _numContacts)
    {
        std::cout << "\n";
        // std::cout << "--------------------------------------------" << std::endl;
        std::cout << "\e[32mFirst Name:     \e[0m" << _contacts[index].FirstName() << std::endl;
        std::cout << "\e[32mLast Name:      \e[0m" << _contacts[index].LastName() << std::endl;
        std::cout << "\e[32mNickname:       \e[0m" << _contacts[index].Nickname() << std::endl;
        std::cout << "\e[32mPhone Number:   \e[0m" << _contacts[index].PhoneNumber() << std::endl;
        std::cout << "\e[32mDarkest Secret: \e[0m" << _contacts[index].DarkestSecret() << std::endl;
        // std::cout << "--------------------------------------------" << std::endl;
        std::cout << "\n";
    }
    else {
        std::cout << "\e[31mError: The index you entered is out of range.\e[0m" << std::endl;
    }
}

