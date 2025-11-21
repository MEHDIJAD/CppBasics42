#include <iostream>
#include <string>


int main(void)
{
    std::string brain = "HI THIS IS BRAIN";

    std::string *stringPTR;
    stringPTR = &brain;

    std::string &stringREF = brain; /* we cant do the same in pointers*/

    std::cout << "The memory address of the string variable: " << (void*)&brain << std::endl;

    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;

    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "The value of the string variable: " << brain << std::endl;

    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;

    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

}
