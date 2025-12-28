### Learning Purpose of `ex03`

The exercise is designed to teach you two main things:

1.  **Interfaces:** How to write flexible code that relies on abstract contracts (`ICharacter`, `IMateriaSource`) rather than concrete classes. This is a fundamental principle of good object-oriented design.
2.  **Memory Ownership:** This is the most critical part. The exercise creates complex rules to force you to think about who is responsible for `delete`ing every object created with `new`. The `unequip()` rule, in particular, is a classic example of a "trap" to make you consider what happens when ownership of a pointer is abandoned.

### Memory Leak Analysis and Fix

Your code was very well-structured and handled almost all memory management correctly, including deep copies and destructor cleanup. I found and fixed one memory leak:

*   **The Leak:** In your `Character::equip` method, if the inventory was full, you would print a message and exit the function. However, the `AMateria* m` that was passed to the function was created with `new` in `main` (via `createMateria`). Since it wasn't equipped, and `equip` didn't delete it, that memory was lost forever.
*   **The Fix:** I added `delete m;` to the `if` block that handles a full inventory. Now, if a `Character` cannot equip a `Materia`, it correctly disposes of it, preventing the leak.

Your implementation is now more robust and correctly handles all the memory management scenarios presented by the exercise.
