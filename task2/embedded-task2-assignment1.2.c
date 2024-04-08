#include <stdio.h>
int main() {
   int num = 0x123456;  
   int *ptr = &num;  

   // *ptr++ 
   printf("*ptr++ = %06x (value at *ptr, then ptr is incremented)\n", *ptr++);

   // *++ptr 
   printf("*++ptr = %06x (ptr is incremented first, then value at *ptr)\n", *++ptr);

   // ++*ptr 
   printf("++*ptr = %06x (value at *ptr is incremented first)\n", ++*ptr);

return 0;
}