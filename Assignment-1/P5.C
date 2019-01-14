/*
Example program for undef in C language:

This directive undefines existing macro in the program.
*/

#include <stdio.h>
 #define height 100
int main()
{
   printf("First defined value for height    : %d\n",height);
   #undef height          // undefining variable
   #define height 600     // redefining the same for new value
   printf("value of height after undef or redefine:%d",height);
return 0;
}
