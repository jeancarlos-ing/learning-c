/*
    Static Variables in C

    Overview:
    ---------
    The 'static' keyword in C is used to preserve the value of a variable between function calls.
    Static variables are initialized only once and retain their value even after the function exits.

    Example:
        void counter() {
            static int count = 0;
            count++;
            printf("%d\n", count);
        }

    Each time you call counter(), 'count' will keep its value from the previous call.
*/