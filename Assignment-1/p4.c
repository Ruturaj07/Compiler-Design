/*
c) Example program for #if, #else and #endif in C:

    “If” clause statement is included in source file if given condition is true.
    Otherwise, else clause statement is included in source file for compilation and execution.
*/

#include <stdio.h>
#define a 100
int main()
{
   #if (a==100)
  printf("This line will be added in this C file since ");
   #else
   printf("This line will be added in this C file since a is not equal to 100\n");
   #endif
   return 0;
}



