# ex05 - Harl: Explanation

The exercise `ex05` is titled "Harl". The goal is to create a program that simulates a character named Harl who complains at different levels. This exercise focuses on using **pointers to member functions** in C++.

### The Core Task

You need to create a `Harl` class. This class will have:

1.  **Private Member Functions:** Four private functions, each representing a different complaint level:
    *   `debug()`: Prints a debug message.
    *   `info()`: Prints an info message.
    *   `warning()`: Prints a warning message.
    *   `error()`: Prints an error message.

2.  **Public Member Function:** A single public function, `complain()`, which takes a string as a parameter:
    *   `void complain(std::string level);`

### How `complain()` Should Work

The `complain()` function is the main part of this exercise. It needs to take the input `level` string (e.g., "DEBUG", "INFO", "WARNING", "ERROR") and call the *corresponding private member function*.

The key constraint is that you **must use an array of pointers to member functions** to associate the level strings with the actual function calls. You should not use a long `if/else if/else` chain.

Here's the conceptual breakdown of the `complain` function's logic:

1.  **Create an array of strings** for the complaint levels: `["DEBUG", "INFO", "WARNING", "ERROR"]`.
2.  **Create an array of pointers to member functions** that corresponds to the strings: `[&Harl::debug, &Harl::info, &Harl::warning, &Harl::error]`.
3.  **Loop through the array of strings** to find a match with the input `level`.
4.  When a match is found, use the index from the string array to get the correct function pointer from the function pointer array.
5.  **Call the member function** using that pointer.

### Example Usage in `main()`

Your `main()` function will be simple. It should:
1.  Create an instance of the `Harl` class.
2.  Call the `complain()` method with different levels to demonstrate that it works.

```cpp
#include "Harl.hpp"

int main() {
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("INVALID"); // Should do nothing

    return 0;
}
```

### Files to Create

To complete this exercise, you will need:

*   `Harl.hpp`: The header file defining the `Harl` class.
*   `Harl.cpp`: The implementation file for the `Harl` class methods.
*   `main.cpp`: The main file to test your `Harl` class.
*   `Makefile`: To compile everything.

This exercise is a great way to learn about a more advanced C++ feature (pointers to member functions) and see a practical use case for them as an alternative to `if/else` or `switch` statements.

# N5 - How will the variable that holds the array of pointers be declared?

That's a great question, and it gets to the heart of using pointers to member functions.

No, it won't be a "double pointer" in the traditional sense of `Type**`. Pointers to member functions have a very specific and unique syntax in C++. They are not like pointers to regular functions or data pointers.

A pointer to a member function needs to know:
1.  The **return type** of the function.
2.  The **class** it belongs to.
3.  The **parameters** it takes.

For your `Harl` class, the private member functions (`debug`, `info`, `warning`, `error`) all have:
*   Return type: `void`
*   Class: `Harl`
*   Parameters: `(void)` (or `()`)

So, a single pointer to one of these member functions would be declared like this:

```cpp
void (Harl::*myFunctionPtr)(void);
```

*   `void`: The return type of the member function.
*   `(Harl::*myFunctionPtr)`: This part declares `myFunctionPtr` as a pointer to a member of the `Harl` class. The `*` is inside the parentheses to indicate it's a pointer to a member, not a pointer to a function that returns a `Harl::*`.
*   `(void)`: The parameters the member function takes.

### Array of Pointers to Member Functions

To hold an array of these, you would declare it like this:

```cpp
void (Harl::*functionPtrArray[])(void);
```

Or, if you want to initialize it immediately:

```cpp
void (Harl::*functionPtrArray[])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
```

### How to Call Through the Pointer

To call a member function through such a pointer, you need an *instance* of the class. You use the `.*` (dot-star) or `->*` (arrow-star) operators.

If you have a `Harl` object:

```cpp
Harl myHarl;
void (Harl::*ptr)(void) = &Harl::debug;

(myHarl.*ptr)(); // Calls myHarl.debug()
```

If you have a pointer to a `Harl` object:

```cpp
Harl* myHarlPtr = new Harl();
void (Harl::*ptr)(void) = &Harl::info;

(myHarlPtr->*ptr)(); // Calls myHarlPtr->info()
delete myHarlPtr;
```

So, to answer your question directly: **No, it's not a double pointer in the `Type**` sense. It's an array of a special type of pointer called "pointer to member function," which has its own unique syntax.**

This is a key concept for `ex05`.