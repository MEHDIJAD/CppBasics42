#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
   private:
    Contact _Contacts[8];
    int _NumContacts;
    int _nextIndex;

   public:
    /* 1. Default Constructor */
    PhoneBook();

    /* 2. Copy Constructor */
    PhoneBook(const PhoneBook &other);

    /* 3. Copy Assignment Operator */
    PhoneBook &operator=(const PhoneBook &other);

    void AddContact();
    void DisplayContacts();
    void OneContact(int index);
    int  NumContact() const;

    /* 4. Destructor */
    ~PhoneBook();
};

#endif
