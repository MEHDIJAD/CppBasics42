# N4 - How to check if a file exists with fstream?

To check if a file exists and can be opened with `fstream`, you typically attempt to open the file and then check if the `fstream` object is in a good state.

Here's how you can do it:

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string filename = "non_existent_file.txt";
    std::ifstream inputFile(filename); // Attempt to open the file for reading

    if (inputFile.is_open()) { // Check if the file was successfully opened
        std::cout << "File '" << filename << "' opened successfully." << std::endl;
        // You can now read from the file
        inputFile.close(); // Close the file when done
    } else {
        std::cout << "Error: Could not open file '" << filename << "'." << std::endl;
        // The file might not exist, or there might be permission issues.
    }

    filename = "existent_file.txt"; // Assuming this file exists for demonstration
    // To test this, you might create an empty file named "existent_file.txt"
    // in the same directory as your executable.
    std::ofstream outputFile(filename); // Attempt to open the file for writing

    if (outputFile.is_open()) {
        std::cout << "File '" << filename << "' opened successfully for writing." << std::endl;
        outputFile << "This is a test." << std::endl;
        outputFile.close();
    } else {
        std::cout << "Error: Could not open file '" << filename << "' for writing." << std::endl;
    }

    return 0;
}
```

**Explanation:**

1.  **Include `<fstream>`:** This header provides the `std::ifstream` (for input/reading) and `std::ofstream` (for output/writing) classes.
2.  **Create an `fstream` object:**
    *   `std::ifstream inputFile(filename);` attempts to open the file specified by `filename` for reading.
    *   `std::ofstream outputFile(filename);` attempts to open the file for writing.
3.  **Check `is_open()`:** After attempting to open the file, call the `is_open()` method on the `fstream` object. It returns `true` if the file was successfully opened, and `false` otherwise.
4.  **Implicit conversion to `bool`:** You can also use the `fstream` object directly in a boolean context (e.g., `if (inputFile)`), as it implicitly converts to `true` if the stream is in a good state (file opened, no errors) and `false` otherwise. This is a more concise way to write the check.

    ```cpp
    std::ifstream inputFile(filename);
    if (inputFile) { // Equivalent to if (inputFile.is_open())
        // ...
    }
    ```

This is the standard and most robust way to check for file existence and accessibility when using `fstream` in C++.

# N4 - What about std::ios modes?

You're asking about `std::ios_base::openmode` flags, often just called `std::ios` modes, which control how a file is opened with `fstream`. These flags can be combined using the bitwise OR operator (`|`).

Here are the most common `std::ios_base::openmode` flags and their meanings:

*   **`std::ios::in`**: Open for reading (input). This is the default for `std::ifstream`.
*   **`std::ios::out`**: Open for writing (output). This is the default for `std::ofstream`.
    *   If the file already exists, its contents are **truncated** (deleted) before writing.
    *   If the file does not exist, it is created.
*   **`std::ios::app`**: Append mode. All output operations are performed at the end of the file, effectively appending to its current content.
    *   If the file does not exist, it is created.
*   **`std::ios::trunc`**: Truncate mode. If the file already exists, its contents are discarded (truncated) before opening. This is implied by `std::ios::out` if `std::ios::app` is not also specified.
*   **`std::ios::ate`**: At end. The file's read/write position is moved to the end of the file upon opening. However, you can seek to any other position.
*   **`std::ios::binary`**: Open the file in binary mode. By default, files are opened in text mode, where character translations (like `\n` to `\r\n` on Windows) might occur. In binary mode, no such translations happen.
*   **`std::ios::noreplace`**: (C++11 and later) If the file already exists, the open operation fails. This is useful for ensuring you don't accidentally overwrite an existing file.

### How to use them:

You pass these flags as a second argument to the `fstream` constructor or to the `open()` member function.

**Examples:**

1.  **Open for reading (default for `ifstream`):**
    ```cpp
    std::ifstream file("example.txt", std::ios::in);
    // or simply:
    // std::ifstream file("example.txt");
    ```

2.  **Open for writing, truncating if it exists (default for `ofstream`):**
    ```cpp
    std::ofstream file("example.txt", std::ios::out);
    // or simply:
    // std::ofstream file("example.txt");
    ```

3.  **Open for writing, appending to the end:**
    ```cpp
    std::ofstream file("log.txt", std::ios::out | std::ios::app);
    // std::ios::out is often combined with std::ios::app for clarity,
    // though std::ios::app usually implies std::ios::out.
    ```

4.  **Open for both reading and writing:**
    ```cpp
    std::fstream file("data.bin", std::ios::in | std::ios::out);
    ```

5.  **Open for both reading and writing in binary mode:**
    ```cpp
    std::fstream file("image.jpg", std::ios::in | std::ios::out | std::ios::binary);
    ```

6.  **Open for writing, but fail if the file already exists:**
    ```cpp
    std::ofstream file("new_file.txt", std::ios::out | std::ios::noreplace);
    if (!file.is_open()) {
        std::cerr << "Error: File already exists or cannot be created." << std::endl;
    }
    ```

These modes provide fine-grained control over how your C++ programs interact with files.

# N4 - How to find and replace in a std::string?

For finding and replacing within a `std::string` in C++, there are several member functions that are very helpful. You don't need to reinvent the wheel.

The main functions you'll want to use from the `<string>` library are:

1.  **`find()`**: To locate the substring you want to replace.
2.  **`erase()`**: To remove the old substring.
3.  **`insert()`**: To add the new substring.

Here's a breakdown of how they work together in a loop to replace all occurrences of a substring (`s1`) with another (`s2`) within a single `std::string` object (like a line you've read from a file).

### The `find()` method:

```cpp
size_t find (const string& str, size_t pos = 0) const;
```

*   It searches for the first occurrence of `str` within the string.
*   `pos` is the position to start the search from. This is crucial for finding all occurrences.
*   It returns the position of the first character of the found substring.
*   If the substring is not found, it returns a special value called `std::string::npos`.

### The `erase()` method:

```cpp
string& erase (size_t pos = 0, size_t len = npos);
```

*   It removes a portion of the string.
*   `pos` is the starting position of the characters to be removed.
*   `len` is the number of characters to remove.

### The `insert()` method:

```cpp
string& insert (size_t pos, const string& str);
```

*   It inserts a new string (`str`) into the current string.
*   `pos` is the position where the new string should be inserted.

### Putting It All Together (The Strategy):

Here is the common pattern to replace all occurrences of `s1` with `s2` in a string called `line`:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string line = "I like cats. My cat is a good cat.";
    std::string s1 = "cat";
    std::string s2 = "dog";

    size_t pos = 0; // Start searching from the beginning of the line

    // Loop as long as we keep finding s1
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        // s1 was found at position 'pos'

        // Step 1: Erase the old string (s1)
        line.erase(pos, s1.length());

        // Step 2: Insert the new string (s2)
        line.insert(pos, s2);

        // Step 3: Move past the inserted string to avoid infinite loops
        // if s2 contains s1 (e.g., replacing "a" with "apple")
        pos += s2.length();
    }

    std::cout << "Result: " << line << std::endl;
    // Expected output: Result: I like dogs. My dog is a good dog.

    return 0;
}
```

This loop is the core logic you would apply to each line you read from your input file in `ex04`.

```
