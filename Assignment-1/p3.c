/*b) Example program for #ifndef and #endif in C:

    #ifndef exactly acts as reverse as #ifdef directive. If particular macro is not defined, “If” clause statements are included in source file.
    Otherwise, else clause statements are included in source file for compilation and execution.*/

#include <stdio.h>
#define RAJU 100
int main()
{
   #ifndef SELVA
   {
      printf("SELVA is not defined. So, now we are going to define here\n");
      #define SELVA 300
   }
   #else
   printf("SELVA is already defined in the program");
   #endif
   return 0;
 
}

