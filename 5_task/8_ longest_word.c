

#include <iostream>
void  longest_word(const char* str, char* result) {
    char new_res[100];
    int now_res = 0;
    int p1 = 0, p2 = 0;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == ' ') {
            p1 = p2;
            p2 = i;
        }
        if (p2 - p1 - 1 > now_res) {
            now_res = p2 - p1 - 1;
            for (int j = 0; j < now_res; ++j) {
                new_res[j] = str[p1 + 1 + j];
            }
        }
    }
    for (int i = 0; new_res[i]; ++i) {
        *result = new_res[i];
        ++result;
    }
}
int main()
{
    char str[100];
    char result[100];
    scanf("%[^\n]", str);
    longest_word(str, result);
    for (int i = 0; result[i]; ++i) {
        printf("%c", result[i]);
    }

}

