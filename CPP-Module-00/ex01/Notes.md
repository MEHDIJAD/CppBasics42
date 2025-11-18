## getline 

```c++
// Version A: Reads until a newline '\n' (Default)
std::istream& getline(std::istream& input, std::string& str);

// Version B: Reads until a custom delimiter character
std::istream& getline(std::istream& input, std::string& str, char delimiter);
```

It returns a reference to the input stream (std::istream&) that you passed to it.

If you called std::getline(std::cin, myStr);, it returns std::cin.

### Why is this useful?
Because streams in C++ can be treated like booleans (true/false).

True: If the line was read successfully.

False: If it hit the End of File (EOF) or an error occurred.

This allows you to use it directly in loops or if-statements:

```c++
// This loop keeps running as long as getline successfully reads a line
while (std::getline(std::cin, line)) {
    std::cout << "You typed: " << line << std::endl;
}
```
In short: It returns the stream object, which evaluates to false if the reading failed (or finished).