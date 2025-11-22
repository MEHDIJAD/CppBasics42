#include <iostream>

typedef void (*funcPtr)();

void HelloWorld(){
    std::cout << "Hello, World!" << std::endl;
}

int main(void)
{
    funcPtr ptr = HelloWorld;

    ptr();

}
