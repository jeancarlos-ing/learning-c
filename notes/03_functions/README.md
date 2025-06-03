# Functions in C

Functions in C allow you to organize code into reusable blocks. Each function can take arguments (inputs) and return a value (output). In C, you must always declare the types of arguments and the return type.

## Function Definition and Return Types

A function definition specifies the return type, the function name, and the parameter list.  
Example: a function that takes an `int` and returns an `int`:

```c
#include <stdio.h>

int plus_one(int n) {
    return n + 1;
}

int main(void) {
    int i = 10, j;
    j = plus_one(i);
    printf("i + 1 is %d\n", j);
}
```

- `int` before `plus_one` is the return type.
- `int n` is a parameter (a local variable that receives a copy of the argument).

## Passing by Value

In C, **arguments are always passed by value**.  
This means the function receives a copy of the argument, not the original variable.

Example:

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
- The value of `i` is copied into `a`. Changing `a` does not affect `i`.

## Functions with No Arguments or No Return Value

- Use `void` to indicate a function takes no arguments or returns no value.

Example: function with no arguments and no return value:

```c
void hello(void) {
    printf("Hello, world!\n");
}

int main(void) {
    hello();
}
```

## Function Prototypes

A **function prototype** tells the compiler about a function’s name, return type, and parameters before its actual definition.  
This allows you to call functions before they are defined in the code.

Example:

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

- The prototype is just the first line of the function with a semicolon.

**Note:**

- If you call a function without a prototype or definition, you’ll get a compiler error in modern C.
- Standard library functions (like `printf`) are declared in header files (e.g., `#include <stdio.h>`).

## Empty Parameter Lists

- Always use `void` in the parameter list to indicate a function takes no arguments.
- Example:
    - `void foo(void);` // Correct
    - `void foo();`     // Not recommended for prototypes

Leaving out `void` in a prototype disables type checking for parameters, which can lead to bugs.

## Key Points

- Functions help organize and reuse code.
- Always declare argument and return types.
- Arguments are passed by value (copied).
- Use `void` for functions with no parameters or no return value.
- Use function prototypes to declare functions before use.
- Always specify `void` in empty parameter lists for clarity and safety.
