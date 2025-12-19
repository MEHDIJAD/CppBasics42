#include <iostream>
using namespace std;

class Base {
public:

    // Virtual function
	void display() {
        cout << "Base class function";
    }
};

class Derived : public Base {
public:

    // this is called Redefining the function 
    void display() {
        cout << "Derived class function";
    }
};

int main() {

	Derived d;

	d.display();
    return 0;
}
