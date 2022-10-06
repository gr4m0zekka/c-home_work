

#include <iostream>



int main()
{
    char text[50];
    scanf("%[^\n]", text);
    int i = 0;
    while (text[i] != 0) {
        if (text[i] == ' ' && isalpha(text[i - 1])) {
            printf("! ");
        }
        else {
            printf("%c", text[i]);
        }
        ++i;
    }
}

