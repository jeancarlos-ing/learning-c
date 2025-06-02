# Introduction to C

C is a foundational programming language that gives you direct control over memory and hardware. While it was considered high-level in the 1970s compared to assembly, today C is seen as low-level because it exposes the inner workings of the computer.

---

## Why Learn C?

- **Close to the Machine:**  
  C lets you see how software interacts directly with memory and hardware. There are no safety nets—mistakes can crash your program, but this is a valuable learning experience.

- **Still Relevant:**  
  C is widely used in operating systems, embedded systems, and high-performance software. Even with newer languages like Rust, C remains essential in many areas.

- **Influential:**  
  Many modern languages (Go, Rust, Swift, Python, JavaScript, Java, and more) are influenced by C. If you know C, you'll recognize familiar concepts in these languages.

---

## The Main Challenge: Pointers

Pointers are variables that store memory addresses. While the idea is simple, C requires you to use them explicitly, which can feel strange at first. Once you understand pointers, the rest of C becomes much easier.

---

## Summary

Learning C brings you close to the core of how computers work. It's a powerful language that reveals what happens "under the hood" and is a great foundation for any programmer.

---

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

---

## Explanation

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

---

## How to Compile and Run

On Unix-like systems (Linux, macOS, WSL), compile your program with:

```sh
gcc -o hello hello.c
```

Then run it with:

```sh
./hello
```

You should see:

```x
Hello, World!
```

Congratulations! You've written and run your first C program.

---

## Compilation Details

Let's talk about how C programs are built and what happens behind the scenes.

In C, you write **source code** that must be **compiled** into an **executable** before it can run on your computer. Compilation is the process of converting your human-readable C code into machine code (the 1s and 0s that the CPU can execute directly).

Unlike languages like JavaScript or Python, where code is often run directly or compiled to bytecode for a virtual machine, C code is compiled into native machine code for your operating system and hardware. This makes C programs fast and efficient.

> **Note:** Many languages have both interpreted and compiled aspects. For example, Python and Java also compile code to an intermediate form (bytecode), but C typically compiles directly to machine code. There are even C interpreters, but compiling is the standard approach.

The **C compiler** is the tool that performs this compilation. A common compiler is `gcc`, which is available on most Unix-like systems and can be run from the terminal or through an IDE.

---

## Compiling with gcc

Suppose you have a source file called `hello.c` in your current directory. You can compile it into an executable named `hello` with this command:

```sh
gcc -o hello hello.c
```

- `-o hello` tells gcc to name the output file `hello`.
- `hello.c` is the source file to compile.

If your program is split across multiple source files, you can compile them together by listing all the `.c` files:

```sh
gcc -o awesomegame ui.c characters.c npc.c items.c
```

This will produce a single executable called `awesomegame` that includes all the code from the listed files.

This is enough to get started. Later, you will learn more about compiling larger projects, using object files, and other advanced build techniques.

---

## Building with `clang` on macOS

On macOS, the default C compiler is **Clang**, not GCC.

However, macOS includes a `gcc` command that actually uses Clang behind the scenes. So running:

```sh
gcc hello.c -o hello
```

still works for most basic purposes.

If you want the official GCC compiler, you can install it using Homebrew:

```sh
brew install gcc
```

---

## Building from an IDE

If you're using an **Integrated Development Environment (IDE)**, you usually don't need to compile from the command line. Here's how to build and run in some popular IDEs:

### Visual Studio (Windows)

- **Build:** `Ctrl + F7`
- **Run (without debugger):** `Ctrl + F5`

### VS Code (Cross-platform)

- **Run with debugger:** `F5`  
  Make sure to install the **C/C++ extension** by Microsoft.

### Xcode (macOS)

- **Build:** `Command + B`
- **Run:** `Command + R`  
  To install command-line tools, search for:  
  `"Xcode command line tools installation"`

---

### Pro Tip

Even if you're using an IDE, try compiling from the command line at least once. It deepens your understanding of how C programs are built and run — and it's a key part of programming history!

---

## C Versions: A Historical Overview

The C programming language has evolved significantly over the years, with various versions specifying its dialect. These versions, often named after the year of their specification, define the language's features and behavior.

### Notable Versions

- **C K&R (1978):**  
  The original version, created by Brian Kernighan and Dennis Ritchie. It forms the foundation of C, though code written under this standard is rare to find today.

- **C89/C90 (1989/1990):**  
  The American National Standards Institute (ANSI) produced C89, establishing a lasting standard. The International Organization for Standardization (ISO) released C90, which is identical to C89.

- **C95:**  
  A minor addition to C89 that introduced better support for extended characters.

- **C99:**  
  A major revision that added several new features, the most remembered being `//` style comments. It is currently the most widely used version of C.

- **C11:**  
  This major update included support for Unicode and multi-threading. When using these features, one should consider potential portability loss with systems still adhering to the C99 standard.

- **C17/C18 (2017/2018):**  
  A bugfix update to C11. C17 is the official name, although its publication was delayed until 2018. Both names are generally interchangeable.

- **C23:**  
  The most recent specification of the C language.

---

### Using a Specific C Standard

You can force GCC to use one of these standards with the `-std=` command line argument. If you want it to be picky about the standard, add `-pedantic`.

For example, to compile with C11:

```sh
gcc -std=c11 -pedantic foo.c
```

Or to compile with the latest version (C23):

```sh
gcc -Wall -Wextra -std=c23 -pedantic foo.c
```
