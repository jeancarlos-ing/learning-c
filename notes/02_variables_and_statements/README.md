# Variables and Statements in C

Understanding variables, types, and operators is fundamental in C programming. Here’s a concise and clear summary:

## What is a Variable?

A **variable** is a human-readable name for a value stored in memory. Instead of using memory addresses directly, we use variable names to make code easier to read and write.

## Naming Variables

- Use letters (`A-Z`, `a-z`), digits (`0-9`), and underscores (`_`).
- Cannot start with a digit.
- Cannot start with two underscores (`__`) or an underscore followed by a capital letter (reserved for system use).
- Unicode may be supported, but stick to standard characters for portability.

## Variable Types

C is a statically-typed language. You must declare the type of each variable before using it. Common types include:

| Type           | Example           | C Type   |
|-|-|-|
| Integer        | `3490`            | `int`    |
| Floating Point | `3.14159`         | `float`  |
| Character      | `'c'`             | `char`   |
| String         | `"Hello, world!"` | `char *` |

- **Declaration:** `int i; float f;`
- **Initialization:** Always initialize variables before use, as uninitialized variables contain garbage values.

**Example:**
```c
#include <stdio.h>

int main(void) {
    int i = 2;
    float f = 3.14;
    char *s = "Hello, world!";
    printf("%s  i = %d and f = %f\n", s, i, f);
    return 0;
}
```

## Boolean Types

- In C, `0` is **false**, any nonzero value is **true**.
- Traditionally, `int` is used for boolean logic.
- Modern C (C99 and later) supports `bool` via `<stdbool.h>`.

**Example:**
```c
#include <stdbool.h>
bool x = true;
if (x) {
    printf("x is true!\n");
}
```
> Only `1` is equal to `true`. Other nonzero values are "truthy" but not strictly equal to `true`.

## Operators and Expressions

### Arithmetic Operators

- `+` Addition
- `-` Subtraction
- `*` Multiplication
- `/` Division
- `%` Modulo (remainder)

**Shorthand:**
```c
i += 3; // Same as i = i + 3
```
No exponentiation operator; use `pow()` from `<math.h>`.

### Ternary Operator

A compact way to write conditional expressions:
```c
y += x > 10 ? 17 : 37;
```
Equivalent to:
```c
if (x > 10)
    y += 17;
else
    y += 37;
```
**Example:**
```c
printf("The number %d is %s.\n", x, x % 2 == 0 ? "even" : "odd");
```

### Increment and Decrement

- `i++` (post-increment): Use `i`, then increment.
- `++i` (pre-increment): Increment, then use `i`.

**Example:**
```c
int i = 10;
int j = 5 + i++; // j = 15, i = 11
j = 5 + ++i;     // j = 17, i = 12
```

### Comma Operator

Allows multiple expressions in one statement; evaluates left to right, returns the last value.
```c
x = (1, 2, 3); // x is 3
```
Commonly used in `for` loops:
```c
for (i = 0, j = 10; i < 100; i++, j++)
    printf("%d, %d\n", i, j);
```

### Comparison and Boolean Operators

- `==` Equal to
- `!=` Not equal to
- `<`, `>`, `<=`, `>=` Less/greater than (or equal)
- `&&` Logical AND
- `||` Logical OR
- `!` Logical NOT

**Example:**
```c
if (x < 10 && y > 20)
    printf("Condition met!\n");
```

### The `sizeof` Operator

Returns the size (in bytes) of a variable or type.

**Example:**
```c
int a = 999;
printf("%zu\n", sizeof a);      // Size of variable a
printf("%zu\n", sizeof(int));   // Size of type int
printf("%zu\n", sizeof 3.14);   // Size of a double literal
```
- Returns a value of type `size_t`.
- Useful for memory management and portability.

## Summary Table

| Concept         | Example                                  | Notes                                  |
|-----------------|------------------------------------------|----------------------------------------|
| Declaration     | `int i;`                                 | Must declare before use                |
| Initialization  | `int i = 2;`                             | Always initialize                      |
| Boolean         | `if (x)`                                 | 0 is false, nonzero is true            |
| Arithmetic      | `i += 3;`                                | Shorthand for `i = i + 3`              |
| Ternary         | `y += x > 10 ? 17 : 37;`                 | Short conditional                      |
| Increment       | `i++`, `++i`                             | Post/pre increment                     |
| Comparison      | `a == b`, `a != b`, `a < b`              | Use `==` for comparison, not `=`       |
| Boolean logic   | `&&`, `||`, `!`                          | And, or, not                           |
| Sizeof          | `sizeof(int)`                            | Returns size in bytes                  |


# Flow Control in C

Flow control statements let you decide how your program runs, repeat actions, and make choices. The main constructs are `if`, `else`, `while`, `do-while`, `for`, and `switch`.

## Statements and Blocks

- After an `if`, `while`, or similar statement, you can write **one statement** or a **block** (multiple statements inside `{}`).
- **Best practice:** Always use curly braces `{}` to avoid mistakes and improve readability.

**Example:**
```c
if (x == 10) {
    printf("x is 10\n");
    printf("This also happens when x is 10\n");
}
```

## The `if`, `else if`, and `else` Statements

Use `if` to run code only if a condition is true.  
`else if` and `else` let you check multiple conditions.

**Example:**
```c
int i = 99;

if (i == 10)
    printf("i is 10!\n");
else if (i == 20)
    printf("i is 20!\n");
else if (i == 99) {
    printf("i is 99! My favorite\n");
    printf("Really.\n");
}
else
    printf("i is some other number.\n");
```
- Use `if-else` for flexible conditions (including ranges and variables).
- For many constant values, consider `switch` (see below).

## The `while` Loop

Repeats a block while a condition is true.

**Example:**
```c
int i = 0;
while (i < 10) {
    printf("i is now %d!\n", i);
    i++;
}
printf("All done!\n");
```

**Infinite loop:**
```c
while (1) {
    // Runs forever
}
```

## The `do-while` Loop

Like `while`, but always runs the block at least once (condition checked after the block).

**Example:**
```c
int i = 10;
do {
    printf("do-while: i is %d\n", i);
    i++;
} while (i < 10);
```

- Use `do-while` when you want the loop to execute at least once.

**Random example:**

```c
#include <stdio.h>
#include <stdlib.h>

int r;
do {
    r = rand() % 100;
    printf("%d\n", r);
} while (r != 37);
```

## The `for` Loop

Best when you know how many times to repeat.

**Syntax:**
```c
for (initialization; condition; increment) {
    // code
}
```

**Example:**
```c
for (int i = 0; i < 10; i++) {
    printf("i is %d\n", i);
}
```

**Multiple variables:**
```c
for (int i = 0, j = 999; i < 10; i++, j--) {
    printf("%d, %d\n", i, j);
}
```

**Infinite loop:**
```c
for (;;) {
    // Runs forever
}
```

## The `switch` Statement

Selects code to run based on the value of an integer expression.

**Example:**
```c
int goat_count = 2;
switch (goat_count) {
    case 0:
        printf("You have no goats.\n");
        break;
    case 1:
        printf("You have a singular goat.\n");
        break;
    case 2:
        printf("You have a brace of goats.\n");
        break;
    default:
        printf("You have a plethora of goats!\n");
        break;
}
```

- `break` exits the switch.
- `default` runs if no case matches.
- Works with `int`, `char`, and `enum` types (not floats or strings).

**Fall-through:** 

If you omit `break`, execution continues to the next case.
```c
switch (x) {
    case 1:
        printf("1\n");
        // Fall through!
    case 2:
        printf("2\n");
        break;
}
```

> **Tip:** Always comment intentional fall-throughs to avoid confusion.

## Summary Table

| Statement   | Purpose                        | Example Syntax                |
|-|-|-|
| `if`        | Conditional execution          | `if (x > 0) { ... }`          |
| `else if`   | Additional condition           | `else if (x == 0) { ... }`    |
| `else`      | Default action                 | `else { ... }`                |
| `while`     | Loop while condition is true   | `while (x < 10) { ... }`      |
| `do-while`  | Loop at least once             | `do { ... } while (x < 10);`  |
| `for`       | Loop with counter              | `for (i = 0; i < 10; i++)`    |
| `switch`    | Multi-way branch on integer    | `switch (x) { ... }`          |

> Use flow control statements to make your programs flexible, readable, and powerful.