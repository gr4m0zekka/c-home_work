 

#include <iostream>
void encrypt(char* str, int k) {
    for (int i = 0; str[i]; ++i) {
        if ('a' <= str[i] && str[i] <= 'z') {
            if (str[i] + k <= 'z') {
                printf("%c", str[i] + k);
            }
            else {
                printf("%c", 'a' + (str[i] + k) % 'z' - 1);
            }
        }
        if ('A' <= str[i] && str[i] <= 'Z') {
            if (str[i] + k <= 'Z') {
                printf("%c", str[i] + k);
            }
            else {
                printf("%c", 'A' + (str[i] + k) % 'Z' - 1);
            }
        }
    }
}
int main()
{
    char str[50];
    int k;
    scanf("%i", &k);
    scanf("%s", str);
    encrypt(str, k);
}


