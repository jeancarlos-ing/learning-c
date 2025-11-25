#include <stdio.h>
#include <math.h>
#include <unistd.h> // for sleep() on Linux/Mac, use <windows.h> and Sleep(ms) on Windows

// ANSI color codes
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define CYAN "\x1b[36m"

// Basic operations
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
double power(double a, double b) { return pow(a, b); }
double square_root(double a) { return sqrt(a); }
int modulo(int a, int b) { return a % b; }

// Clear input buffer
void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Read double
int read_double(double *num)
{
  if (scanf("%lf", num) != 1)
  {
    clear_buffer();
    return 0;
  }
  return 1;
}

// Read int
int read_int(int *num)
{
  if (scanf("%d", num) != 1)
  {
    clear_buffer();
    return 0;
  }
  return 1;
}

// Show animated banner
void show_banner()
{
  const char *banner[] = {
      "===============================",
      "    SCIENTIFIC CALCULATOR      ",
      "==============================="};
  for (int i = 0; i < 3; i++)
  {
    printf(CYAN "%s\n" RESET, banner[i]);
    usleep(300000); // 0.3 seconds delay
  }
  printf(CYAN "Loading calculator");
  for (int i = 0; i < 3; i++)
  {
    printf(".");
    fflush(stdout);
    usleep(300000); // 0.3 seconds
  }
  printf("\n\n");
}

int main()
{
  int option;
  double a = 0, b, result = 0;
  int ai, bi, mod_result;
  char cont = 'y';
  int use_ans = 0;

  show_banner(); // show animated banner at start

  while (cont == 'y' || cont == 'Y')
  {
    printf(CYAN "-----------------------------\n" RESET);
    printf(YELLOW "Previous result: %.2lf\n" RESET, result);
    printf(GREEN "1. Add (+)\n2. Subtract (-)\n3. Multiply (*)\n4. Divide (/)\n");
    printf("5. Power (^)\n6. Square Root (√)\n7. Modulo (%%)\n8. Exit\n" RESET);
    printf(CYAN "Select option: " RESET);

    if (!read_int(&option))
    {
      printf(RED "Invalid option. Try again.\n" RESET);
      continue;
    }
    if (option == 8)
    {
      printf(CYAN "Exiting... Goodbye!\n" RESET);
      break;
    }

    if (option >= 1 && option <= 5 && result != 0)
    {
      printf("Use previous result (Ans=%.2lf) as first number? (y/n): ", result);
      clear_buffer();
      char ans_choice = getchar();
      if (ans_choice == 'y' || ans_choice == 'Y')
      {
        a = result;
        use_ans = 1;
      }
    }

    if (!use_ans)
    {
      if (option >= 1 && option <= 5)
      {
        printf("Enter first number: ");
        if (!read_double(&a))
        {
          printf(RED "Invalid number.\n" RESET);
          continue;
        }
      }
    }
    use_ans = 0;

    if (option >= 1 && option <= 5)
    {
      printf("Enter second number: ");
      if (!read_double(&b))
      {
        printf(RED "Invalid number.\n" RESET);
        continue;
      }
    }
    else if (option == 6)
    {
      printf("Enter number: ");
      if (!read_double(&a))
      {
        printf(RED "Invalid number.\n" RESET);
        continue;
      }
    }
    else if (option == 7)
    {
      printf("Enter first integer: ");
      if (!read_int(&ai))
      {
        printf(RED "Invalid number.\n" RESET);
        continue;
      }
      printf("Enter second integer: ");
      if (!read_int(&bi))
      {
        printf(RED "Invalid number.\n" RESET);
        continue;
      }
      if (bi == 0)
      {
        printf(RED "Cannot divide by zero.\n" RESET);
        continue;
      }
    }

    printf(CYAN "-----------------------------\n" RESET);
    switch (option)
    {
    case 1:
      result = add(a, b);
      printf(GREEN "Result: %.2lf\n" RESET, result);
      break;
    case 2:
      result = subtract(a, b);
      printf(GREEN "Result: %.2lf\n" RESET, result);
      break;
    case 3:
      result = multiply(a, b);
      printf(GREEN "Result: %.2lf\n" RESET, result);
      break;
    case 4:
      if (b == 0)
      {
        printf(RED "Cannot divide by zero.\n" RESET);
        break;
      }
      result = divide(a, b);
      printf(GREEN "Result: %.2lf\n" RESET, result);
      break;
    case 5:
      result = power(a, b);
      printf(GREEN "Result: %.2lf\n" RESET, result);
      break;
    case 6:
      if (a < 0)
      {
        printf(RED "Cannot take square root of negative number.\n" RESET);
        break;
      }
      result = square_root(a);
      printf(GREEN "Result: %.2lf\n" RESET, result);
      break;
    case 7:
      mod_result = modulo(ai, bi);
      printf(GREEN "Result: %d\n" RESET, mod_result);
      break;
    }
    printf(CYAN "-----------------------------\n" RESET);

    printf("Do you want to perform another operation? (y/n): ");
    clear_buffer();
    cont = getchar();
  }

  return 0;
}
