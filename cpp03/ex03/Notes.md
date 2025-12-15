# Notes on Exercise 03: The Diamond Problem

## The Goal

You need to create a new class, `DiamondTrap`, that inherits from **both** `ScavTrap` **and** `FragTrap` at the same time.

### The Problem: The "Diamond of Dread"

This creates a tricky situation called the **Diamond Problem**. Look at the inheritance structure:

```
      ClapTrap
      /      \
ScavTrap    FragTrap
      \      /
    DiamondTrap
```

1.  `ScavTrap` has a `ClapTrap` inside it.
2.  `FragTrap` also has a `ClapTrap` inside it.
3.  When `DiamondTrap` inherits from both, it gets **two** copies of `ClapTrap`—one from `ScavTrap` and one from `FragTrap`.

This causes two major issues:

*   **Ambiguity:** If you try to call a function from `ClapTrap` (like `getName()`) on a `DiamondTrap` object, the compiler gets confused. It doesn't know which of the two `ClapTrap` copies you want to use. It will give you an "ambiguous request" error.
*   **Redundancy:** Your `DiamondTrap` object is bigger than it needs to be, carrying around two sets of `ClapTrap` attributes.

### The Solution: Virtual Inheritance

The subject mentions a "trick" to solve this. The trick is **virtual inheritance**.

By changing how `ScavTrap` and `FragTrap` inherit from `ClapTrap`, you tell the compiler: "If another class inherits from me and other classes that also have a `ClapTrap`, please make sure there is only **one single, shared** copy of `ClapTrap` at the end."

You need to modify your `ScavTrap` and `FragTrap` header files:

```cpp
// In ScavTrap.hpp
class ScavTrap : public virtual ClapTrap { /* ... */ };

// In FragTrap.hpp
class FragTrap : public virtual ClapTrap { /* ... */ };
```

Now, when `DiamondTrap` inherits from both, they will share a single `ClapTrap` base, and the ambiguity is gone.

### `DiamondTrap` Specifics

*   **Constructor:** Because of virtual inheritance, the `DiamondTrap` constructor is now responsible for initializing the shared `ClapTrap` directly.
    ```cpp
    DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
        // ...
    }
    ```
*   **New Attribute:** It will have its own `private std::string _name;`.
*   **Stats:** You must set its stats to the specified values (HP from `FragTrap`, Energy from `ScavTrap`, etc.) in its constructor.
*   **`attack()`:** It should use `ScavTrap`'s version of `attack()`.
*   **`whoAmI()`:** A new function that prints both its own `_name` and the `ClapTrap` name.

This exercise is all about understanding and solving the Diamond Problem using virtual inheritance.

---

## Question: Can you run the program for ex03 and explain the output?

Of course. The output you're seeing is a perfect demonstration of how virtual inheritance works. Let's focus on the `DiamondTrap` part of the output.

### 1. Construction: The Build-Up

```
ClapTrap MARK-98_clap_name Constructor called
FragTrap MARK-98_clap_name Constructor called
ScavTrap MARK-98_clap_name Constructor called
DiamondTrap constructed
```

This is the most important part. Because you used `virtual` inheritance:
1.  The **ultimate base class** (`ClapTrap`) is constructed **first and only once**. `DiamondTrap`'s constructor is responsible for calling it directly.
2.  Then, the intermediate parents (`FragTrap` and `ScavTrap`) are constructed. Their own calls to the `ClapTrap` constructor are skipped, because the shared `ClapTrap` is already built.
3.  Finally, the `DiamondTrap` constructor's body runs.

### 2. `whoAmI()` Function Call

```
My Diamond name is: MARK-98
My ClapTrap name is: MARK-98_clap_name
```

This shows that your `DiamondTrap` object has two different `name` attributes, as required:
*   One that belongs to the `DiamondTrap` class itself (`MARK-98`).
*   One that belongs to the shared `ClapTrap` sub-object (`MARK-98_clap_name`).

### 3. Destruction: The Reverse Order

```
Destructor called
ScavTrap MARK-98_clap_name Destructor called
FragTrap MARK-98_clap_name Destructor called
ClapTrap MARK-98_clap_name Destructor called
```

Destruction happens in the **exact reverse order of construction**:
1.  The `DiamondTrap` destructor runs first.
2.  The parent class destructors (`ScavTrap`, `FragTrap`) run next, in reverse order of their appearance in the inheritance list.
3.  The single, shared `ClapTrap` base class is destroyed last.

The output perfectly demonstrates that you have successfully solved the Diamond Problem: `ClapTrap` was constructed only once, and all the derived classes share that single instance.
