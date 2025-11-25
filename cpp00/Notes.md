## Compiling

c++ -Wall -Wextra -Werror -std=c++98


C++

```cpp
//	↓↓ THIS IS THE LIST ↓↓
Human(const std::string &name, int age) : _name(name), _age(age) {
    std::cout << "Human Parameterized Constructor Called!" << std::endl;
}
```

## Initializer List
What is it?
It is a way to initialize your class variables before the constructor's body ({ ... }) actually runs.

Why use it instead of writing code inside {}?
Efficiency (Performance):

Initializer List: The variable is created and given a value at the same time.

Inside Body: The variable is created first (default constructor), and then you overwrite it with a new value (assignment). It saves a step.

Mandatory Cases: You must use this list if your class has:

* const variables (constants cannot be changed after creation).

* References (&) (references must be bound when created).

* Objects that don't have a Default Constructor.

Visual Difference
Using Initializer List (Better/Standard):

```c++

Human(string n, int a) : _name(n), _age(a) {
    // Variables are already ready to go!
}
Using Assignment inside Body (Slower/Sometimes Impossible):
```

```cpp

Human(string n, int a) {
    _name = n; // _name was arguably created empty, then overwritten here
    _age = a;
}
```

⚠️ You can use the Member Initializer List (: variable(value)) only with the Constructor, not with other member functions.
It does not work with any other function.


