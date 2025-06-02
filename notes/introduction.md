# Introduction to C

## What to Expect from C

C is a foundational programming language that gives you direct control over memory and hardware. While it was considered high-level in the 1970s compared to assembly, today C is seen as low-level because it exposes the inner workings of the computer.

### Why Learn C?

- **Close to the Machine:**  
  C lets you see how software interacts directly with memory and hardware. There are no safety nets—mistakes can crash your program, but this is a valuable learning experience.
- **Still Relevant:**  
  C is widely used in operating systems, embedded systems, and high-performance software. Even with newer languages like Rust, C remains essential in many areas.
- **Influential:**  
  Many modern languages (Go, Rust, Swift, Python, JavaScript, Java, and more) are influenced by C. If you know C, you'll recognize familiar concepts in these languages.

### The Main Challenge: Pointers

Pointers are variables that store memory addresses. While the idea is simple, C requires you to use them explicitly, which can feel strange at first. Once you understand pointers, the rest of C becomes much easier.

### Summary

Learning C brings you close to the core of how computers work. It's a powerful language that reveals what happens "under the hood" and is a great foundation for any programmer.

## Hello, World! Example

The classic first program in C prints a message to the screen and demonstrates the basic structure of a C program.

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
```

## Hello, World!

The classic first program in C prints a message to the screen and demonstrates the basic structure of a C program.

```c
/* Hello world program */

#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");  // Actually do the work here
    return 0;
}
```

### Explanation

- **Comments:**  
  Anything between `/* ... */` or after `//` is a comment and is ignored by the compiler. Use comments to explain your code.

- **`#include <stdio.h>`:**  
  This line tells the preprocessor to include the standard input/output library, which provides the `printf` function.

- **Preprocessing and Compilation:**  
  Lines starting with `#` are handled by the preprocessor before compilation. The preprocessor processes directives like `#include` and `#define`, then the compiler turns the result into machine code.

- **Header Files:**  
  `<stdio.h>` is a header file that gives access to input/output functions like `printf`. If you try to use `printf` without including this header, the compiler will give an error.

- **The `main` Function:**  
  Every C program starts executing from the `main` function. When the program reaches the end of `main`, it exits.

- **`printf("Hello, World!\n");`:**  
  This line prints the message to the screen. The `\n` is a newline character, which moves the cursor to the next line.

- **`return 0;`:**  
  This signals that the program finished successfully.

### How to Compile and Run

On Unix-like systems (Linux, macOS, WSL), compile your program with:

```sh
gcc -o hello hello.c
```

Then run it with:

```sh
./hello
```

You should see:

```sh
Hello, World!
```

Congratulations! You've written and run your first C program.
