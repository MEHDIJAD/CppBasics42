# ex04 Test Cases

This document outlines various test cases for the `ex04` program, covering correct functionality, edge cases, and error handling.

## Setup

Before running tests, ensure your `ex04` executable is compiled.

```bash
cd ex04
make
```

Create a sample input file `file.txt` for testing:

```bash
echo "This is a test line." > file.txt
echo "Hello world, this is another test." >> file.txt
echo "Test at the beginning." >> file.txt
echo "This line has test in the middle." >> file.txt
echo "And test at the end test." >> file.txt
echo "No match here." >> file.txt
echo "test" >> file.txt
echo "testtesttest" >> file.txt
echo "" >> file.txt # Empty line
echo "This is the final test line." >> file.txt
```

## Test Cases

### 1. Correct Number of Arguments

**Objective:** Verify the program handles an incorrect number of command-line arguments.

*   **Test 1.1: No arguments**
    ```bash
    ./ex04
    ```
    **Expected Output:** Red "Usage" message to `stderr`, exit code `1`.
*   **Test 1.2: One argument**
    ```bash
    ./ex04 file.txt
    ```
    **Expected Output:** Red "Usage" message to `stderr`, exit code `1`.
*   **Test 1.3: Two arguments**
    ```bash
    ./ex04 file.txt s1
    ```
    **Expected Output:** Red "Usage" message to `stderr`, exit code `1`.
*   **Test 1.4: More than three arguments**
    ```bash
    ./ex04 file.txt s1 s2 s3
    ```
    **Expected Output:** Red "Usage" message to `stderr`, exit code `1`.

### 2. Input File Errors

**Objective:** Verify the program handles issues with the input file.

*   **Test 2.1: Input file does not exist**
    ```bash
    ./ex04 non_existent_file.txt s1 s2
    ```
    **Expected Output:** "Error: Could not open input file 'non_existent_file.txt'" to `stderr`, exit code `1`. No `.replace` file should be created.
*   **Test 2.2: Input file has no read permissions**
    ```bash
    # Create a file and remove read permissions
    echo "content" > no_read.txt
    chmod 200 no_read.txt
    ./ex04 no_read.txt s1 s2
    # Revert permissions
    chmod 644 no_read.txt
    rm no_read.txt
    ```
    **Expected Output:** "Error: Could not open input file 'no_read.txt'" to `stderr`, exit code `1`. No `.replace` file should be created.

### 3. Output File Errors

**Objective:** Verify the program handles issues when creating the output file.

*   **Test 3.1: No write permissions in the current directory**
    ```bash
    # Create a directory with no write permissions
    mkdir no_write_dir
    chmod 500 no_write_dir
    # Try to run the program, attempting to create output in this directory
    ./ex04 no_write_dir/file.txt s1 s2 # This assumes file.txt is moved into no_write_dir
    # Revert permissions and clean up
    chmod 755 no_write_dir
    rmdir no_write_dir
    ```
    **Expected Output:** "Error: Could not create output file 'no_write_dir/file.txt.replace'" to `stderr`, exit code `1`.

### 4. String Argument Edge Cases

**Objective:** Verify the program's behavior with special `s1` and `s2` values.

*   **Test 4.1: `s1` is an empty string**
    ```bash
    ./ex04 file.txt "" replacement
    ```
    **Expected Output:** The program should ideally print an error message (e.g., "Error: String to be replaced cannot be empty.") to `stderr` and exit with code `1`. (This requires explicit handling in your code).
*   **Test 4.2: `s2` is an empty string**
    ```bash
    ./ex04 file.txt test ""
    ```
    **Expected Output:** The `file.txt.replace` file should have all occurrences of "test" removed.
*   **Test 4.3: `s1` is not found in the file**
    ```bash
    ./ex04 file.txt nonexistent replacement
    ```
    **Expected Output:** The `file.txt.replace` file should be an exact copy of `file.txt`.

### 5. Replacement Scenarios

**Objective:** Verify the core find-and-replace logic.

*   **Test 5.1: Basic replacement**
    ```bash
    ./ex04 file.txt test exam
    ```
    **Expected Output:** `file.txt.replace` should have all "test" replaced with "exam".
*   **Test 5.2: `s1` and `s2` have different lengths (`s1` shorter than `s2`)**
    ```bash
    ./ex04 file.txt test testing
    ```
    **Expected Output:** `file.txt.replace` should have all "test" replaced with "testing".
*   **Test 5.3: `s1` and `s2` have different lengths (`s1` longer than `s2`)**
    ```bash
    ./ex04 file.txt testing test
    ```
    **Expected Output:** `file.txt.replace` should have all "testing" replaced with "test".
*   **Test 5.4: `s1` contains `s2` (e.g., replacing "apple" with "app")**
    ```bash
    echo "apple pie" > temp.txt
    ./ex04 temp.txt apple app
    # Expected: "app pie"
    rm temp.txt temp.txt.replace
    ```
    **Expected Output:** Correct replacement without infinite loops.
*   **Test 5.5: `s2` contains `s1` (e.g., replacing "app" with "apple")**
    ```bash
    echo "app pie" > temp.txt
    ./ex04 temp.txt app apple
    # Expected: "apple pie"
    rm temp.txt temp.txt.replace
    ```
    **Expected Output:** Correct replacement without infinite loops.
*   **Test 5.6: Multiple occurrences on one line**
    ```bash
    ./ex04 file.txt test exam
    # Check line "And test at the end test." -> "And exam at the end exam."
    # Check line "testtesttest" -> "examexamexam"
    ```
    **Expected Output:** All occurrences on a single line are replaced.
*   **Test 5.7: Empty lines in input**
    ```bash
    ./ex04 file.txt test exam
    # Check the empty line in file.txt
    ```
    **Expected Output:** Empty lines should remain empty in the output.

---
**Note:** For tests involving permissions, remember to revert the permissions after the test to avoid issues with your environment.
