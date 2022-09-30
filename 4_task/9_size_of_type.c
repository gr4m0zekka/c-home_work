

#include <iostream>

int main()
{
    printf("char: %i bites", sizeof(char));
    printf("\n");
    printf("short: %i bites", sizeof(short));
    printf("\n");
    printf("int: %i bites", sizeof(int));
    printf("\n");
    printf("long long: %i bites", sizeof(long long));
    printf("\n");
    printf("size_t: %i bites", sizeof(size_t));
    printf("\n");
    printf("float: %i bites", sizeof(float));
    printf("\n");
    printf("double: %i bites", sizeof(double));
    printf("\n");
    printf("int*: %i bites", sizeof(int*));
    printf("\n");
    int a[10];
    printf("int[10]: %i bites", sizeof(a));
        
    
}

