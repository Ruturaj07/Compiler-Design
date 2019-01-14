/*Example program for conditional compilation directives:
a) Example program for #ifdef, #else and #endif in C:

    “#ifdef” directive checks whether particular macro is defined or not. If it is defined, “If” clause statements are included in source file.
    Otherwise, “else” clause statements are included in source file for compilation and execution.*/

#include <stdio.h>
#define RAJU 100
 
int main()
{
   #ifdef RAJU
   printf("RAJU is defined. So, this line will be added in this C file\n");
   #else
   printf("RAJU is not defined\n");
   #endif
   return 0;
}

