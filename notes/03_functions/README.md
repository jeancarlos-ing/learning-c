# 🛠️ Functions in C

Functions are essential in C for organizing code, avoiding repetition, and making programs easier to read and maintain. This guide explains functions with clear explanations, diagrams, tables, and practical advice.

## 🧩 What is a Function?

A **function** is a reusable block of code that performs a specific task.  
You can "call" a function whenever you need its task done.

**Analogy:**  
Think of a function as a kitchen appliance (like a blender). You give it ingredients (arguments), it does its job, and gives you a result (return value).

## 📝 Function Definition and Return Types

A function definition specifies:

- The return type (what kind of value it gives back)
- The function name
- The parameter list (inputs)

**Example:**

```c
#include <stdio.h>

int plus_one(int n) { // returns int, takes int n
    return n + 1;
}

int main(void) {
    int i = 10, j;
    j = plus_one(i);
    printf("i + 1 is %d\n", j);
}
```

| Part                | Example             | Meaning                                  |
|---------------------|--------------------|------------------------------------------|
| Return type         | `int`              | Function returns an int                  |
| Function name       | `plus_one`         | Name of the function                     |
| Parameter list      | `(int n)`          | Takes one int parameter                  |
| Return statement    | `return n + 1;`    | Gives back a value to the caller         |

## 🔄 Passing by Value

In C, **arguments are always passed by value**.  
This means the function receives a copy of the argument, not the original variable.

**Example:**

```c
void increment(int a) {
    a++;
}

int main(void) {
    int i = 10;
    increment(i);
    printf("i == %d\n", i); // Prints 10, not 11!
}
```

**Diagram:**

```c
[main] i = 10
   |
   v (pass value)
[increment] a = 10 (copy)
   |
   v (a++)
[increment] a = 11
   |
   v (return)
[main] i = 10 (unchanged)
```

**Tip:**  

To modify the original variable, you must use pointers (see the pointers guide).

## 🚫 Functions with No Arguments or No Return Value

- Use `void` to indicate a function takes no arguments or returns no value.

**Example:**

```c
void hello(void) { // No arguments, no return value
    printf("Hello, world!\n");
}

int main(void) {
    hello();
}
```

## 📢 Function Prototypes

A **function prototype** tells the compiler about a function’s name, return type, and parameters before its actual definition.  
This allows you to call functions before they are defined in the code.

**Example:**

```c
#include <stdio.h>

int foo(void); // Prototype

int main(void) {
    int i = foo();
    printf("%d\n", i);
}

int foo(void) { // Definition
    return 3490;
}
```

| Part           | Example         | Meaning                                  |
|----------------|----------------|------------------------------------------|
| Prototype      | `int foo(void);`| Declares function before use             |
| Definition     | `int foo(void)` | Actual code for the function             |

**Note:**  

- If you call a function without a prototype or definition, you’ll get a compiler error in modern C.
- Standard library functions (like `printf`) are declared in header files (e.g., `#include <stdio.h>`).

## ⚠️ Empty Parameter Lists

- Always use `void` in the parameter list to indicate a function takes no arguments.
  - `void foo(void);` // Correct
  - `void foo();`     // Not recommended for prototypes

**Why?**  
Leaving out `void` disables type checking for parameters, which can lead to bugs.

## 📋 Summary Table

| Concept                | Example                | Notes                                  |
|------------------------|------------------------|----------------------------------------|
| Function definition    | `int add(int a, int b)`| Returns int, takes two ints            |
| Function call          | `add(2, 3)`            | Calls function with arguments          |
| No arguments           | `void hello(void)`     | Takes no arguments                     |
| No return value        | `void foo(...)`        | Returns nothing                        |
| Prototype              | `int foo(void);`       | Declare before use                     |
| Return statement       | `return value;`        | Sends value back to caller             |

## 🎨 Visual: Function Call Flow

```c
[main] --calls--> [plus_one]
   |                  |
   |                  v
   |           [return n + 1]
   |                  |
   v                  v
[main] <--- result ---+
```

## 🌈 Conclusions and Tips

- **Functions help organize and reuse code.**
- **Always declare argument and return types.**
- **Arguments are passed by value (copied).**
- **Use `void` for functions with no parameters or no return value.**
- **Use function prototypes to declare functions before use.**
- **Always specify `void` in empty parameter lists for clarity and safety.**
- **Practice writing your own functions for different tasks!**
