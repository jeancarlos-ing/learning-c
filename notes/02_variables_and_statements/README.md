# Variables and Statements

## Variables

People often say "variables have values," but another way to think about it is that a **variable is a human-readable name** for some **data stored in memory**.

Let’s take a brief detour into the world of **pointers**. Don’t worry if it seems confusing at first.

You can imagine computer memory as a **giant array (or list) of bytes**. Each byte is a small unit of storage—like a tiny box that can hold data.

All the data you use (numbers, text, variables, etc.) is stored in these tiny memory boxes.

Some values require **more than one byte** to store. For example, a large number won’t fit in a single box, so it’s stored across multiple consecutive bytes.

Since memory acts like an array, each byte has an **index or position**—this is called its:

- **Address**
- **Location**
- **Pointer**

A **pointer** is simply the number that tells you **where** in memory something is.

But remembering or using memory addresses like `0x4A3B` is inconvenient, so we use **variable names** like `x`, `y`, or `name`. These are just **labels** that point to a memory address where the data is stored.

This is important to understand now because:

- It makes understanding **pointer variables** easier later on—they are variables that **store the memory address of other variables**.
- It helps explain how memory and data are managed in C.

In short:  
A **variable** is a name for a value stored **somewhere in memory** at a specific address.

---

## Variable Naming Rules

You can use characters from `[0-9]`, `[A-Z]`, `[a-z]`, and underscores `_` to name variables, but with a few important restrictions:

- You **can’t start** a variable name with a digit (`0-9`).
- You **can’t start** a variable name with **two underscores** (`__`). These are reserved for internal use by compilers and standard libraries.
- You **can’t start** a variable name with an underscore followed by a capital letter (e.g., `_A`). These are also reserved for internal or system use.

### Unicode in Variable Names

- You *can* use Unicode characters (like accented letters or non-Latin scripts) in some compilers.
- There are technical rules defined in the standard (like §D.2), but they’re complex.
- In practice: **just try it**—if your compiler accepts it, great. Otherwise, avoid it.

---

## Variable Types

C is strict about data types. Here are some common basic types:

| Description        | Example         | C Type     |
|--------------------|-----------------|------------|
| Integer            | `3490`          | `int`      |
| Floating-point     | `3.14159`       | `float`    |
| Character (single) | `'c'`           | `char`     |
| String             | `"Hello, world!"`       | `char *`   |

C tries to **automatically convert between numeric types**, but conversions between strings and numbers are **manual**.

Most types in C are **variants** of the ones above.

### Declaration

Before you use a variable, you must **declare** it by specifying its type.  
Once declared, a variable’s type **cannot be changed** later during runtime.

Let’s revisit our earlier "Hello, World!" example and add a couple of variables:

```c
#include <stdio.h>

int main(void)
{
    int i;    // Holds signed integers, e.g., -3, 0, 1, 42
    float f;  // Holds floating-point numbers, e.g., -3.14, 2.71

    printf("Hello, World!\n");
}
```

We’ve declared two variables but haven’t used them yet. They're also **uninitialized**, meaning their values are **unknown**.

> **Uninitialized variables contain garbage values.**  
> They must be **initialized before use**, or you risk using meaningless or unpredictable data.

Sometimes they might **appear to be 0**, but **never assume this**always explicitly initialize your variables.

Let’s assign a value and print it:

```c
int main(void)
{
    int i;

    i = 2;  // Assign the value 2 to variable i

    printf("Hello, World!\n");
}
````

Printing Variable Values with printf()
To print variable values, we use format specifiers in the printf() function:

- %d → for integers
- %f → for floating-point numbers
- %s → for strings

Full examplo:

````c
#include <stdio.h>

int main(void)
{
    int i = 2;
    float f = 3.14;
    char *s = "Hello, world!";  // char * is the string type

    printf("%s  i = %d and f = %f!\n", s, i, f);
}
````

Output:

````
Hello, world!  i = 2 and f = 3.14!
````

## Boolean Types

Seccion to continued ...