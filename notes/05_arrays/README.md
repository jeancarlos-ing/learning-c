# Arrays in C

Arrays are a fundamental feature in C. While C is considered a low-level language, it provides built-in support for arrays, which are used in almost every program. However, arrays in C are closely related to pointers, and understanding this relationship is key to mastering them.

## What is an Array?

An **array** is a collection of elements of the same type, stored in contiguous memory locations.  
You access each element using an index, starting at 0.

### Example: Declaring and Using an Array

```c
#include <stdio.h>

int main(void)
{
    int i;
    float f[4];  // Declare an array of 4 floats

    f[0] = 3.14159;  // Indexing starts at 0
    f[1] = 1.41421;
    f[2] = 1.61803;
    f[3] = 2.71828;

    // Print all elements
    for (i = 0; i < 4; i++) {
        printf("%f\n", f[i]);
    }
}
```

**Key Points:**

- You must specify the array size at declaration.
- The size must be a constant (fixed at compile time).
- Indexing starts at 0.

## Getting the Length of an Array

C does **not** store the length of an array for you. You must manage it yourself.

### Trick: Using `sizeof` to Get Array Length

```c
int x[12];  // 12 ints

printf("%zu\n", sizeof x);     // Total bytes (e.g., 48)
printf("%zu\n", sizeof(int));  // Bytes per int (e.g., 4)
printf("%zu\n", sizeof x / sizeof(int));  // Number of elements (12)
```

**Note:**  
This trick only works in the scope where the array is declared. If you pass the array to a function, it decays to a pointer and `sizeof` gives the pointer size, not the array size.

### Example: Why `sizeof` Fails in Functions

```c
void foo(int x[12])
{
    printf("%zu\n", sizeof x);     // Prints pointer size, not array size!
}
```

> **Tip:** Always keep track of array lengths in a separate variable.

## Array Initializers

You can initialize arrays with values at declaration:

```c
int a[5] = {22, 37, 3490, 18, 95};
```

- If you provide fewer values than the array size, the rest are set to zero.
- If you provide more, the compiler will warn or error.

```c
int a[5] = {22, 37, 3490}; // Same as {22, 37, 3490, 0, 0}
int a[100] = {0};          // All elements set to zero
```

### Indexed Initializers

You can set specific elements by index:

```c
int a[10] = {0, 11, 22, [5]=55, 66, 77};
// Result: 0 11 22 0 0 55 66 77 0 0
```

### Letting C Infer the Size

```c
int a[] = {22, 37, 3490}; // Size is 3
```

## Out-of-Bounds Access

C does **not** check array bounds. Accessing out-of-bounds elements is undefined behavior.

### Example: Printing Beyond Array End

```c
int a[5] = {22, 37, 3490, 18, 95};

for (int i = 0; i < 10; i++) {  // BAD: prints too many elements!
    printf("%d\n", a[i]);
}
```

**Possible Output:**

```c
22
37
3490
18
95
32765
1847052032
...
```

> **Warning:** Never access arrays out of bounds! It can cause crashes or unpredictable results.

---

## Multidimensional Arrays

You can declare arrays with more than one dimension:

```c
int a[10];         // 1D array
int b[2][7];       // 2D array (2 rows, 7 columns)
int c[4][5][6];    // 3D array
```

### Initializing Multidimensional Arrays

```c
int a[2][5] = {
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9}
};
```

**Printing All Elements:**

```c
for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 5; col++) {
        printf("(%d,%d) = %d\n", row, col, a[row][col]);
    }
}
```

**Output:**

```c
(0,0) = 0
(0,1) = 1
...
(1,4) = 9
```

### Explicit Index Initialization

```c
int a[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
// Identity matrix:
// 1 0 0
// 0 1 0
// 0 0 1
```

## Arrays and Pointers

Arrays and pointers are closely related in C.

### Getting a Pointer to an Array

```c
int a[5] = {11, 22, 33, 44, 55};
int *p;

p = &a[0]; // Points to the first element
// or simply:
p = a;     // Equivalent!
```

- `a` by itself is a pointer to the first element.
- `*p` is the value pointed to (e.g., `11`).

### Passing Arrays to Functions

When you pass an array to a function, you are really passing a pointer to its first element.

#### Example: Different Ways to Declare Array Parameters

```c
void times2(int *a, int len) { ... }
void times3(int a[], int len) { ... }
void times4(int a[5], int len) { ... }
```

All three are equivalent in function signatures.

#### Example: Modifying an Array in a Function

```c
void double_array(int *a, int len)
{
    for (int i = 0; i < len; i++)
        a[i] *= 2;
}

int main(void)
{
    int x[5] = {1, 2, 3, 4, 5};
    double_array(x, 5);
    // x is now {2, 4, 6, 8, 10}
}
```

> **Tip:** Changes made to the array in the function are visible to the caller.

### Passing Multidimensional Arrays to Functions

For multidimensional arrays, you must specify all dimensions except the first:

```c
void print_2D_array(int a[2][3])
{
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}
```

These two signatures are equivalent:

```c
void print_2D_array(int a[2][3])
void print_2D_array(int a[][3])
```

- The compiler only needs to know the second (and further) dimensions to calculate memory offsets.

> **Warning:** C does not check array bounds at runtime. Always ensure you stay within valid indices!

## 📋 Summary Table

| Concept                | Example                                  | Notes                                  |
|------------------------|------------------------------------------|----------------------------------------|
| Declare array          | `int a[5];`                              | 5 ints, indices 0–4                    |
| Initialize array       | `int a[3] = {1,2,3};`                    | Sets a[0]=1, a[1]=2, a[2]=3            |
| Get length (trick)     | `sizeof a / sizeof a[0]`                 | Only in scope where declared           |
| Out-of-bounds access   | `a[10]` (if size is 5)                   | Undefined behavior                     |
| Multidimensional array | `int b[2][3];`                           | 2 rows, 3 columns                      |
| Pass to function       | `void foo(int a[], int len)`             | Pass pointer and length                |
| Pointer to array       | `int *p = a;`                            | Points to first element                |

---

## 🎨 Visual Summary

### Array in Memory

```c
+-------+-------+-------+-------+-------+
| a[0]  | a[1]  | a[2]  | a[3]  | a[4] |
+-------+-------+-------+-------+-------+
   |       |       |       |       |
  22      37     3490     18      95
```

### Passing Array to Function

```c
[main] --(pointer to a[0])--> [function]
   |                                 |
   v                                 v
[Array in memory]           [Function modifies array]
```

---

## 🌈 Tips and Recommendations

- **Always keep track of array sizes**—C won’t do it for you!
- **Never access out-of-bounds elements.**
- **Use initializers to set arrays at declaration.**
- **Remember:** Arrays decay to pointers when passed to functions.
- **For multidimensional arrays, specify all but the first dimension in function parameters.**
- **Practice:** Write small programs to get comfortable with arrays and their quirks.
