# 🛠️ Functions in C

Functions are essential in C for organizing code, avoiding repetition, and making programs easier to read and maintain. This guide explains functions with clear explanations, diagrams, tables, and practical advice.

## What is a Function?

A **function** is a reusable block of code that performs a specific task.  
You can "call" a function whenever you need its task done.

**Analogy:**  
Think of a function as a kitchen appliance (like a blender). You give it ingredients (arguments), it does its job, and gives you a result (return value).

## Function Definition and Return Types

A function definition specifies:

- The return type (what kind of value it gives back)
- The function name
- The parameter list (inputs)

**Example:**

```c
#include <stdio.h>

int plus_one(int n)  // The "definition"
{
    return n + 1;
}
```

| Part                | Example            | Meaning                                  |
|---------------------|--------------------|------------------------------------------|
| Return type         | `int`              | Function returns an int                  |
| Function name       | `plus_one`         | Name of the function                     |
| Parameter list      | `(int n)`          | Takes one int parameter                  |
| Return statement    | `return n + 1;`    | Gives back a value to the caller         |

### Calling a Function

You can call a function from another function (like `main`). The return value can be stored in a variable.

```c
int main(void)
{
    int i = 10, j;
    j = plus_one(i);  // The "call"
    printf("i + 1 is %d\n", j);
}
```

### Diagram: Function Call Flow

```c
[main] --calls--> [plus_one]
   |                  |
   |                  v
   |           [return n + 1]
   |                  |
   v                  v
[main] <--- result ---+
```

> **Tip:** You must define a function before you use it, or declare a prototype (see below).

## The `void` Keyword

- `void` as a parameter list means the function takes **no arguments**.
- `void` as a return type means the function returns **no value**.

**Example:**

```c
#include <stdio.h>

// This function takes no arguments and returns no value:
void hello(void)
{
    printf("Hello, world!\n");
}

int main(void)
{
    hello();  // Prints "Hello, world!"
}
```

## Passing by Value

In C, **arguments are always passed by value**.  
This means the function receives a copy of the argument, not the original variable.

**Example:**

```c
#include <stdio.h>

void increment(int a)
{
    a++;
}

int main(void)
{
    int i = 10;
    increment(i);
    printf("i == %d\n", i);  // Prints 10, not 11!
}
```

**Why does this print 10?**

- The value of `i` (10) is copied into `a`.
- `a` is incremented to 11, but `i` in `main` is unchanged.
- When the function ends, `a` is discarded.

### Diagram: Passing by Value

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

> **Tip:** To modify the original variable, you must use pointers (see the pointers guide).

## Function Prototypes

A **function prototype** tells the compiler about a function’s name, return type, and parameters before its actual definition.  
This allows you to call functions before they are defined in the code.

**Example:**

```c
#include <stdio.h>

int foo(void);  // This is the prototype!

int main(void)
{
    int i;
    i = foo();
    printf("%d\n", i);  // 3490
}

int foo(void)  // This is the definition, just like the prototype!
{
    return 3490;
}
```

| Part           | Example         | Meaning                                  |
|----------------|----------------|------------------------------------------|
| Prototype      | `int foo(void);`| Declares function before use             |
| Definition     | `int foo(void)` | Actual code for the function             |

> **Tip:** If you call a function without a prototype or definition, you'll get a compiler error in modern C.

### Why do we need prototypes?

- The compiler needs to know the function's signature before it is called.
- Prototypes enable type checking for arguments and return values.
- Standard library functions (like `printf`) are declared in header files (e.g., `#include <stdio.h>`).

## Empty Parameter Lists

You might see these from time to time in older code, but you shouldn’t ever code one up in new code.  
**Always use `void` to indicate that a function takes no parameters.**

### Function Definition

```c
void foo()  // Should really have a `void` in there
{
    printf("Hello, world!\n");
}
```

While the spec says this is as-if you’d indicated `void`, the `void` type is there for a reason. **Use it.**

### Function Prototype

There is a significant difference between using `void` and not in a prototype:

```c
void foo();
void foo(void);  // Not the same!
```

- `void foo();` — Tells the compiler nothing about the parameters (turns off type checking).
- `void foo(void);` — Tells the compiler this function takes **no arguments** (enables type checking).

> **Recommendation:**  
> With a prototype, **always use `void`** when you have an empty parameter list.

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

## 🌈 Tips and Recommendations

- **Functions help organize and reuse code.**
- **Always declare argument and return types.**
- **Arguments are passed by value (copied).**
- **Use `void` for functions with no parameters or no return value.**
- **Use function prototypes to declare functions before use.**
- **Always specify `void` in empty parameter lists for clarity and safety.**
- **Practice writing your own functions for different tasks!**
