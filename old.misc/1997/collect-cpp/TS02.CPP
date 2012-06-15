 #include <stdio.h>
 #include <stdlib.h>

 int compare(int *x, int *y)
 {
    return( *x - *y );
 }

 int main(void)
 {
    int array[5] = {35, 87, 46, 99, 12};
    size_t nelem = 5;
    int key;
    int *result;

    key = 99;
    result = (int *) lfind(&key, array, &nelem,
	      sizeof(int), (int(*)(const void *,const
void *))compare);
    if (result)
       printf("Number %d found\n",key);
    else
       printf("Number %d not found\n",key);

    return 0;
 }
