/*

Variables and Types

Data types

C has several types of variables, but there are a few basic types

- Integers - Whole numbers which can be either positive or negative. Defined usen 'char', 'int', 'long', 'long long'.

- Unsigned integers - Whole numbers which can only be positive. Defined usen 'unsigned char', 'unsigned int', 'unsigned long', 'unsignedlong long'.

- Floating point numbers - real numbers (numbers with fractions). Defined using float and double.

- Structures - will be explained later, in the Structures section.

The diferent types of variables define their bounds. A 'char' can range only from -128 to 127, wheareas a 'long' can range from -2,147,483,648 to 2,147,483,647 ('long' and other numeric data types may have another range on different computers, for example - from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 on 64-bit computer).

Note that C des not have boolean type. Usually, it is defined using the following notation:

#define BOOL char
#define FALSE 0
#define TRUE 1

C uses arrays of characters to defined strings, and will be explained in the String section.

Defining variables

For numbers, we will usually use the type 'int', On most computers today. it is 32-bit number, which means the number can range from -2,147,483,648 to 2,147,483,647.

To define the variables 'foo' and 'bar', we need to use following syntax:

int a = 0, b = 1, c = 2, d = 3, e = 4;
a = b - c + d * e;

will print 1-2+3*4 = 11
printf("%d", a);

*/

#include <stdio.h>

int main()
{
    int a = 3;
    float b = 4.5;
    double c = 5.25;
    float sum = a + b + c;

    printf("The sum of a, b, and c is %f.", sum);
    return 0;
}
