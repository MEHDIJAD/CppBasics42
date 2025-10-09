#include "header.h"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _numContacts;
        int     _nextIndex;

    public:
        PhoneBook();
        void AddContact();
        void DisplayContacts();
        void OneContact(int index);
        int getNumContact() const;
};
