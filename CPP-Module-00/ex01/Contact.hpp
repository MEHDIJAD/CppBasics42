#include "header.h"

class Contact
{
    private:
        std::string _FirstName;
        std::string _LastName;
        std::string _Nickname;
        std::string _PhoneNumber;
        std::string _DarkestSecret;

    public:
        // Setters
        bool SetFirstName(std::string FirstName);
        bool SetLastName(std::string LastName);
        void SetNickname(std::string Nickname);
        bool SetPhoneNumber(std::string PhoneNumber);
        void SetDarkestSecret(std::string DarkestSecret);

        // Getters
        std::string FirstName();
        std::string LastName();
        std::string Nickname();
        std::string PhoneNumber();
        std::string DarkestSecret();
};
