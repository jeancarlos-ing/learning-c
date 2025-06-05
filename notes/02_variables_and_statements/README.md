# 📦 Variables and Statements in C

Understanding variables, types, operators, and flow control is fundamental in C programming. This guide explains each concept with clear explanations, diagrams, tables, and practical advice so you can truly master the basics.

## Variables

A **variable** is a human-readable name that refers to some data in memory.  
Think of memory as a big array of bytes, each with its own address (like mailboxes). Variables are labels for these addresses, so you don't have to remember the numbers.

### Diagram: Variables and Memory

```sh
+---------+---------+---------+---------+
|   i     |   f     |   s     |   ...  |
+---------+---------+---------+---------+
|   2     |  3.14   | "Hello" |        |
+---------+---------+---------+---------+
  0x1000    0x1004    0x1008
```

### Why Variables?

- Easier to use names than raw memory addresses.
- Help organize and make code readable.
- Essential for storing and manipulating data.

### Variable Names

| Rule                                    | Example         | Allowed? | Why?                                 |
|-----------------------------------------|-----------------|----------|-------------------------------------|
| Letters, digits, underscores            | `score1`        | ✅       | Standard naming                     |
| Cannot start with a digit               | `1score`        | ❌       | Not allowed in C                     |
| Cannot start with two underscores (`__`)| `__myVar`       | ❌       | Reserved for system use              |
| Cannot start with `_` + uppercase       | `_MyVar`        | ❌       | Reserved for system use              |
| Use descriptive names                   | `totalAmount`   | ✅       | Improves code readability            |
| Case sensitive                          | `Age` vs `age`  | Both     | Different variables in C             |

### Variable Types

C is a statically-typed language. You must declare the type of each variable before using it.

| Type           | Example Value | C Type   | Example Declaration      |
|----------------|--------------|----------|-------------------------|
| Integer        | `3490`       | `int`    | `int age = 3490;`       |
| Floating point | `3.14159`    | `float`  | `float pi = 3.14159;`   |
| Character      | `'c'`        | `char`   | `char letter = 'c';`    |
| String         | `"Hello"`    | `char *` | `char *msg = "Hello";`  |

**Example:**

```c
#include <stdio.h>

int main(void)
{
    int i = 2;
    float f = 3.14;
    char *s = "Hello, world!";

    printf("%s  i = %d and f = %f!\n", s, i, f);
    return 0;
}
```

**Output:**

```sh
Hello, world!  i = 2 and f = 3.14!
```

> **Tip:** Always initialize variables before use. Uninitialized variables contain garbage values!

### Boolean Types

Historically, C didn't have a Boolean type. In C, `0` means **false**, and any nonzero value means **true**.

**Example:**

```c
int x = 1;
if (x) {
    printf("x is true!\n");
}
```

Modern C (C99 and later) supports `bool` via `<stdbool.h>`:

```c
#include <stdbool.h>
bool x = true;
if (x) {
    printf("x is true!\n");
}
```

| C Type    | Header         | True Value | False Value | Example Usage         |
|-----------|---------------|------------|-------------|----------------------|
| `int`     | (none)        | any ≠ 0    | 0           | `if (x) { ... }`     |
| `bool`    | `<stdbool.h>` | `true`     | `false`     | `bool x = true;`     |

> **Tip:** Only `1` is strictly equal to `true`. Other nonzero values are "truthy" but not strictly equal to `true`.

## Operators and Expressions

C operators should be familiar if you know other languages. Here are the essentials:

### Arithmetic Operators

| Operator | Meaning        | Example      | Result   |
|----------|---------------|--------------|----------|
| `+`      | Addition      | `2 + 3`      | `5`      |
| `-`      | Subtraction   | `5 - 2`      | `3`      |
| `*`      | Multiplication| `4 * 2`      | `8`      |
| `/`      | Division      | `8 / 2`      | `4`      |
| `%`      | Modulo        | `7 % 3`      | `1`      |

**Shorthand:**

```c
i += 3; // Same as i = i + 3
```

> **Note:** No exponentiation operator in C. Use `pow()` from `<math.h>`.

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

### Pre-and-Post Increment/Decrement

- `i++` (post-increment): Use `i`, then increment.
- `++i` (pre-increment): Increment, then use `i`.

**Example:**

```c
int i = 10;
int j = 5 + i++; // j = 15, i = 11
j = 5 + ++i;     // j = 17, i = 12
```

> **Tip:** Most common in `for` loops.

### The Comma Operator

Allows multiple expressions in one statement; evaluates left to right, returns the last value.

**Example:**

```c
x = (1, 2, 3); // x is 3
```

Common in `for` loops:

```c
for (i = 0, j = 10; i < 100; i++, j++)
    printf("%d, %d\n", i, j);
```

### Comparison Operators

| Operator | Meaning         | Example         |
|----------|----------------|-----------------|
| `==`     | Equal to       | `a == b`        |
| `!=`     | Not equal to   | `a != b`        |
| `<`      | Less than      | `a < b`         |
| `>`      | Greater than   | `a > b`         |
| `<=`     | Less or equal  | `a <= b`        |
| `>=`     | Greater/equal  | `a >= b`        |

> **Tip:** Don't mix up assignment (`=`) with comparison (`==`)!

### Boolean Operators

| Operator | Meaning        | Example         |
|----------|----------------|-----------------|
| `&&`     | Logical AND    | `a && b`        |
| `\|\|`   | Logical OR     | `a \|\| b`      |
| `!`      | Logical NOT    | `!a`            |

**Example:**

```c
if (x < 10 && y > 20)
    printf("Both conditions are true!\n");
```

### The `sizeof` Operator

Returns the size (in bytes) of a variable or type.

| Expression         | Meaning                | Example Result (on 64-bit) |
|--------------------|------------------------|----------------------------|
| `sizeof(int)`      | Size of int type       | `4`                        |
| `sizeof a`         | Size of variable `a`   | depends on type            |
| `sizeof 3.14`      | Size of double literal | `8`                        |

**Example:**

```c
int a = 999;
printf("%zu\n", sizeof a);      // Prints 4 on most systems
printf("%zu\n", sizeof(int));   // Prints 4
printf("%zu\n", sizeof 3.14);   // Prints 8
```

> **Tip:** `sizeof` is evaluated at compile time, not runtime.

## Flow Control

Flow control statements let you decide how your program runs, repeat actions, and make choices.

### The `if-else` Statement

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

> **Tip:** Always use curly braces `{}` for clarity, even if optional.

### The `while` Statement

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
    printf("This repeats forever.\n");
}
```

### The `do-while` Statement

Like `while`, but always runs the block at least once.

**Example:**

```c
int i = 10;
do {
    printf("do-while: i is %d\n", i);
    i++;
} while (i < 10);
```

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

### The `for` Statement

Best when you know how many times to repeat.

**Syntax:**

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

### The `switch` Statement

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
        printf("You have a bona fide plethora of goats!\n");
        break;
}
```

#### How `switch` Works

- Evaluates the expression.
- Jumps to the matching `case`.
- Runs code until a `break` or end of switch.
- If no `case` matches, runs `default` (if present).

#### Diagram: Switch Flow

```c
[switch(expr)]
   |
   +--> [case 0] --break--> [end]
   |
   +--> [case 1] --break--> [end]
   |
   +--> [case 2] --break--> [end]
   |
   +--> [default] --break--> [end]
```

#### Fall-through Example

If you omit `break`, execution continues to the next case:

```c
switch (x) {
    case 1:
        printf("1\n");
        // Fall through!
    case 2:
        printf("2\n");
        break;
    case 3:
        printf("3\n");
        break;
}
```

If `x == 1`, this prints:

```c
1
2
```

> **ProTip:** Always comment intentional fall-throughs to avoid confusion and bugs.

#### Using Characters and Enums

You can use `char` and `enum` types in `switch` because they are integer types:

```c
char c = 'b';
switch (c) {
    case 'a':
        printf("It's 'a'!\n");
        break;
    case 'b':
        printf("It's 'b'!\n");
        break;
    case 'c':
        printf("It's 'c'!\n");
        break;
}
```

## 📋 Summary Table

| Concept         | Example                                  | Notes                                  |
|-----------------|------------------------------------------|----------------------------------------|
| Declaration     | `int i;`                                 | Must declare before use                |
| Initialization  | `int i = 2;`                             | Always initialize                      |
| Boolean         | `if (x)`                                 | 0 is false, nonzero is true            |
| Arithmetic      | `i += 3;`                                | Shorthand for `i = i + 3`              |
| Ternary         | `y += x > 10 ? 17 : 37;`                 | Short conditional                      |
| Increment       | `i++`, `++i`                             | Post/pre increment                     |
| Comparison      | `a == b`, `a != b`, `a < b`              | Use `==` for comparison, not `=`       |
| Boolean logic   | `&&`, `\|\|`, `!`                          | And, or, not                           |
| Sizeof          | `sizeof(int)`                            | Returns size in bytes                  |
| Flow control    | `if`, `while`, `for`, `switch`           | Control program execution              |

## 🎨 Visual Summary

### Variables in Memory

```sh
+---------+---------+---------+---------+
|   i     |   f     |   s     |   ...  |
+---------+---------+---------+---------+
|   2     |  3.14   | "Hello" |        |
+---------+---------+---------+---------+
```

### Flow Control Diagram

```c
[Start]
   |
   v
[if/else] --> [while/for/do-while] --> [switch]
   |
   v
[End]
```

## 🌈 Tips and Recommendations

- **Always initialize variables** before use to avoid unpredictable results.
- **Use curly braces** for all control structures, even if optional, to prevent bugs.
- **Practice writing small programs** to get comfortable with each concept.
- **Read error messages carefully**—they help you learn.
- **Experiment!** Change values, try new operators, and see what happens.
- **Draw your own diagrams** to visualize how your code flows and how variables change.
