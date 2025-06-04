# 🌟 Variables and Statements in C

Understanding variables, types, operators, and flow control is fundamental in C programming. This guide explains each concept with clear explanations, diagrams, tables, and practical advice so you can truly master the basics.

## 🗃️ What is a Variable?

A **variable** is a named storage location in memory for a value.  
Think of a variable as a labeled box on a shelf:

```c
+---------+
|  age    |  <-- variable name (label)
+---------+
|   25    |  <-- value inside the box
+---------+
```

### Memory Analogy

Imagine your computer's memory as a row of mailboxes, each with a unique address:

```c
Address: 1000   1001   1002   1003   1004
         +----+ +----+ +----+ +----+ +----+
         |    | |    | |    | |    | |    |
         +----+ +----+ +----+ +----+ +----+
```

When you declare a variable, you are reserving one or more of these mailboxes.

## 🏷️ Naming Variables

| Rule                                   | Example         | Allowed? | Why?                                 |
|-----------------------------------------|-----------------|----------|--------------------------------------|
| Letters, digits, underscores            | `score1`        | ✅       | Standard naming                      |
| Cannot start with a digit               | `1score`        | ❌       | Not allowed in C                     |
| Cannot start with two underscores (`__`)| `__myVar`       | ❌       | Reserved for system use              |
| Cannot start with `_` + uppercase       | `_MyVar`        | ❌       | Reserved for system use              |
| Use descriptive names                   | `totalAmount`   | ✅       | Improves code readability            |
| Case sensitive                          | `Age` vs `age`  | Both     | Different variables in C             |

**Examples:**

```c
int age;
float temperature;
char _grade;
int totalAmount;
```

## 🧮 Variable Types

C is a statically-typed language. You must declare the type of each variable before using it.

| C Type   | Description         | Example Value     | Example Declaration      | Bytes (typical) |
|----------|---------------------|-------------------|-------------------------|-----------------|
| `int`    | Integer             | `42`              | `int age = 42;`         | 4               |
| `float`  | Floating point      | `3.14`            | `float pi = 3.14;`      | 4               |
| `double` | Double precision    | `2.71828`         | `double e = 2.71828;`   | 8               |
| `char`   | Character           | `'A'`             | `char grade = 'A';`     | 1               |
| `char*`  | String (pointer)    | `"Hello"`         | `char *msg = "Hello";`  | 8 (on 64-bit)   |

**Declaration and Initialization:**

```c
int i = 2;
float f = 3.14;
char *s = "Hello, world!";
```

**Output Example:**

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

## 🔢 Boolean Types

| C Type    | Header         | True Value | False Value | Example Usage         |
|-----------|---------------|------------|-------------|----------------------|
| `int`     | (none)        | any ≠ 0    | 0           | `if (x) { ... }`     |
| `bool`    | `<stdbool.h>` | `true`     | `false`     | `bool x = true;`     |

**Example:**

```c
#include <stdbool.h>
bool x = true;
if (x) {
    printf("x is true!\n");
}
```

**Tip:**  
In C, any nonzero value is considered true, but only `1` is strictly equal to `true`.

## ➕ Operators and Expressions

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

**Example:**

```c
int a = 10, b = 3;
printf("%d\n", a + b); // 13
printf("%d\n", a % b); // 1
```

### Ternary Operator

A compact way to write conditional expressions:

```c
int result = (x > 10) ? 1 : 0;
```

Equivalent to:

```c
if (x > 10)
    result = 1;
else
    result = 0;
```

**Example:**

```c
printf("The number %d is %s.\n", x, x % 2 == 0 ? "even" : "odd");
```

### Comparison and Boolean Operators

| Operator | Meaning         | Example         | Result   |
|----------|----------------|-----------------|----------|
| `==`     | Equal to       | `a == b`        | true/false |
| `!=`     | Not equal to   | `a != b`        | true/false |
| `<`      | Less than      | `a < b`         | true/false |
| `>`      | Greater than   | `a > b`         | true/false |
| `<=`     | Less or equal  | `a <= b`        | true/false |
| `>=`     | Greater/equal  | `a >= b`        | true/false |
| `&&`     | Logical AND    | `a && b`        | true/false |
| `\|\|`   | Logical OR     | `a \|\| b`      | true/false |
| `!`      | Logical NOT    | `!a`            | true/false |

**Example:**

```c
if (x < 10 && y > 20)
    printf("Condition met!\n");
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
printf("Size of int: %zu\n", sizeof(int));
```

## 🧩 Flow Control in C

Flow control statements let you decide how your program runs, repeat actions, and make choices.

### Program Flow Diagram

```c
[Start]
   |
   v
[if/else] --> [while/for/do-while] --> [switch]
   |
   v
[End]
```

### Statements and Blocks

After an `if`, `while`, or similar statement, you can write **one statement** or a **block** (multiple statements inside `{}`).

**Best practice:** Always use curly braces `{}` to avoid mistakes and improve readability.

**Example:**

```c
if (x == 10) {
    printf("x is 10\n");
    printf("This also happens when x is 10\n");
}
```

---

### The `if`, `else if`, and `else` Statements

| Structure                | Description                        | Example                                 |
|--------------------------|------------------------------------|-----------------------------------------|
| `if (condition) { ... }` | Executes block if condition is true| `if (score >= 90) { printf("A"); }`     |
| `else if (cond) { ... }` | Checks another condition           | `else if (score >= 80) { printf("B"); }`|
| `else { ... }`           | Executes if all above are false    | `else { printf("C or below"); }`        |

**Example:**

```c
if (score >= 90)
    printf("A\n");
else if (score >= 80)
    printf("B\n");
else
    printf("C or below\n");
```

---

### The `while` Loop

Repeats a block while a condition is true.

**Example:**

```c
int i = 0;
while (i < 5) {
    printf("%d\n", i);
    i++;
}
```

**Flow Diagram:**

```c
[Start] -> [Check Condition] --yes--> [Block] --> [Check Condition]
                      | no
                      v
                   [End]
```

### The `do-while` Loop

Like `while`, but always runs the block at least once.

**Example:**

```c
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 5);
```

### The `for` Loop

Best when you know how many times to repeat.

**Syntax:**

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

**Flow Diagram:**

```c
[Init] -> [Check Condition] --yes--> [Block] --> [Increment] --> [Check Condition]
                      | no
                      v
                   [End]
```

### The `switch` Statement

Selects code to run based on the value of an integer expression.

| Structure                        | Description                        | Example                                 |
|-----------------------------------|------------------------------------|-----------------------------------------|
| `switch (expr) { ... }`           | Multi-way branch                   | `switch (day) { ... }`                  |
| `case value:`                     | Block for specific value           | `case 1: printf("Monday"); break;`      |
| `default:`                        | Block if no case matches           | `default: printf("Other day"); break;`  |

**Example:**

```c
switch (day) {
    case 1: printf("Monday\n"); break;
    case 2: printf("Tuesday\n"); break;
    default: printf("Other day\n"); break;
}
```

## 📋 Summary Tables

### Variable and Operator Summary

| Concept         | Example                                  | Notes                                  |
|-----------------|------------------------------------------|----------------------------------------|
| Declaration     | `int i;`                                 | Must declare before use                |
| Initialization  | `int i = 2;`                             | Always initialize                      |
| Boolean         | `if (x)`                                 | 0 is false, nonzero is true            |
| Arithmetic      | `i += 3;`                                | Shorthand for `i = i + 3`              |
| Ternary         | `y += x > 10 ? 17 : 37;`                 | Short conditional                      |
| Increment       | `i++`, `++i`                             | Post/pre increment                     |
| Comparison      | `a == b`, `a != b`, `a < b`              | Use `==` for comparison, not `=`       |
| Boolean logic   | `&&`, `\|\|`, `!`                        | And, or, not                           |
| Sizeof          | `sizeof(int)`                            | Returns size in bytes                  |

### Flow Control Summary

| Statement   | Purpose                        | Example Syntax                |
|-------------|-------------------------------|-------------------------------|
| `if`        | Conditional execution          | `if (x > 0) { ... }`          |
| `else if`   | Additional condition           | `else if (x == 0) { ... }`    |
| `else`      | Default action                 | `else { ... }`                |
| `while`     | Loop while condition is true   | `while (x < 10) { ... }`      |
| `do-while`  | Loop at least once             | `do { ... } while (x < 10);`  |
| `for`       | Loop with counter              | `for (i = 0; i < 10; i++)`    |
| `switch`    | Multi-way branch on integer    | `switch (x) { ... }`          |

## 🎨 Visual Summary

### Variables in Memory

```c
+---------+---------+---------+---------+
|   i     |   f     |   s     |   ...   |
+---------+---------+---------+---------+
|   2     |  3.14   | "Hello" |         |
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

### Example: Full Program Flow

```c
[Start]
   |
   v
[Declare variables]
   |
   v
[Input/assign values]
   |
   v
[if/else or switch to make decisions]
   |
   v
[while/for/do-while to repeat actions]
   |
   v
[Output results]
   |
   v
[End]
```

## 🌈 Conclusions and Tips

- **Always initialize variables** before use to avoid unpredictable results.
- **Use curly braces** for all control structures, even if optional, to prevent bugs.
- **Practice writing small programs** to get comfortable with each concept.
- **Read error messages carefully**—they help you learn.
- **Experiment!** Change values, try new operators, and see what happens.
- **Draw your own diagrams** to visualize how your code flows and how variables change.
