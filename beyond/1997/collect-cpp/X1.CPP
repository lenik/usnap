#include <stdio.h>
#include <alloc.h>
#include <string.h>

int main(void)
{
   char *str;

   /* allocate memory for string */
   str = (char *) malloc(10);
   char *s2 = (char *)malloc(100000);

   /* copy "Hello" into string */
   strcpy(str, "Hello");

   printf("String is %s\n  Address is %p\n", str, str);
   str = (char *) realloc(str, 2000000);
   printf("String is %s\n  New address is %p\n", str, str);

   /* free memory */
   free(str);

   return 0;
}
