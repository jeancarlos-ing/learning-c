/*
    Strings in C

    Overview:
    ---------
    Strings in C are arrays of characters, terminated by a null character '\0'.

    Defining Strings:
    -----------------
        char *name = "John Smith"; // Read-only string
        char name[] = "John Smith"; // Modifiable string

    The size of the array includes space for the null terminator.

    String Formatting:
    -----------------
        printf("%s is %d years old.\n", name, age);

    String Length:
    --------------
        strlen(name); // Returns the length of the string

    String Comparison:
    -----------------
        strncmp(str1, str2, n); // Compares up to n characters

    String Concatenation:
    --------------------
        strncat(dest, src, n); // Appends up to n characters from src to dest
*/

#include <stdio.h>
#include <string.h>

int main()
{
    // Define a read-only string
    char *first_name = "John";
    // Define a modifiable string
    char last_name[] = "Doe";
    char name[100];

    // Change the first letter of last_name
    last_name[0] = 'B';

    // Combine first_name and last_name into name
    sprintf(name, "%s %s", first_name, last_name);

    // Compare the combined name with "John Boe"
    if (strncmp(name, "John Boe", 100) == 0)
    {
        printf("Hecho!\n");
    }

    // Concatenate first_name and last_name into name
    name[0] = '\0'; // Reset name to an empty string
    strncat(name, first_name, 4);
    strncat(name, last_name, 20);

    printf("%s\n", name);

    return 0;
}
