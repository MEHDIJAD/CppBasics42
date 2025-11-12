# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string _FirstName;
        std::string _LastName;
        std::string _Nickname;
        std::string _PhoneNumber;
        std::string _DarkestSecret;

    public:
        /* 1. Default Constructor */
        Contact();
        
        /* 2. Copy Constructor */
        Contact(const Contact& other);

        /* 3. Copy Assignment Operator */
        Contact& operator=(const Contact& other);

        bool SetFirstName(std::string FirstName);
        bool SetLastName(std::string LastName);
        bool SetNickname(std::string Nickname);
        bool SetPhoneNumber(std::string PhoneNumber);
        bool SetDarkestSecret(std::string DarkestSecret);
        
        // Getters
        std::string FirstName();
        std::string LastName();
        std::string Nickname();
        std::string PhoneNumber();
        std::string DarkestSecret();

        /* 4. Destructor */
         ~Contact();
    };

#endif
