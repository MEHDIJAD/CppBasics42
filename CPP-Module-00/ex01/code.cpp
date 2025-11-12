#include <iostream>

class code
{
private:
	std::string _str;
	int _a;
public:
	code();
	code(const code &other);
	code& operator=(const code &other);

	std::string str(){
		return (this->_str);
	}

	int a(){
		return (this->_a);
	}

	~code();
};

code::code() : _str("Hello"), _a(10)
{
}

code::code(const code &other){
	*this = other;
}

code& code::operator=(const code &other)
{
	if (this != &other)
	{
		this->_a = other._a +1; 
		this->_str = other._str + "World";
	}
	return (*this);
}


code::~code(){
}

int main(void)
{
	code a;

	std::cout << a.str() << " " << a.a() << std::endl;  
	
	code b;

	b = a;
	std::cout << b.str() << " " << b.a() << std::endl; 
}

