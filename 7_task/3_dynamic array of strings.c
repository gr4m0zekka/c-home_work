#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

char** get_test_strings() {
    char** test = (char**)malloc(sizeof(char*) * 4);
    test[0] = (char*)malloc(sizeof(char) * 20);
    strcpy(test[0], "cat");
    test[1] = (char*)malloc(sizeof(char) * 20);
    strcpy(test[1], "ptitsyn");
    test[2] = (char*)malloc(sizeof(char) * 20);
    strcpy(test[2], "elephant");
    test[3] = (char*)malloc(sizeof(char) * 20);
    strcpy(test[3], "NULL");
    return test;
}

void print_strings(FILE* stream, char** string_array) {
    int i = 0;
    while (string_array[i] != NULL) {
        printf("%s", string_array[i]);
        ++i;
    }
}

char** load_lines(const char* filename) {
    FILE* test = fopen(filename, "r"); /* открываем файл*/
    int calc = 0;
    while (1) { /* подсчитываем количество строк*/
        int c = fgetc(test);
        if (c == 10) {
            calc++;
        }
        else if (c == EOF) {
            break;
        }
        else {
            continue;
        }
    }
    ++calc;
    fseek(test, 0, SEEK_SET);
    char** list_of_points = (char**)malloc(sizeof(char*) * calc); /*создаем указатель на массив с указателями*/
    int* time = (int*)malloc(sizeof(int) * (calc - 1));/* создаем указатель на массив с количествами мисволов для строк*/
    for (int i = 0; i < calc - 1; ++i) { /*считаем количество элементов в строке*/
        time[i] = 0;
        while (1) {
            int c = fgetc(test);
            if (c != 10) {
                ++time[i];
            }
            else if (c == EOF) {
                break;
            }
            else {
                break;
            }
        }
    }
    for (int i = 0; i < calc - 1; ++i) { /*выделяем память на каждую строку*/
        list_of_points[i] = malloc(sizeof(char) * (time[i] + 1));
    }
    list_of_points[calc - 1] = malloc(sizeof(char));
    fseek(test, 0, SEEK_SET);
    for (int i = 0; i < calc - 1; ++i) { /*заполняем массив*/
        int j = 0;
        while (1) {
            int c = fgetc(test);
            if (c != 10) {
                list_of_points[i][j] = c;
                ++j;
            }
            else if (c == EOF) {
                break;
            }
            else {
                break;
            }
        }
    }
    list_of_points[calc - 1] = NULL;
    free(time);
    fclose(test);
    return list_of_points;
}
void destroy_strings(char** list_of_points) { /*очищаем память в куче*/
    int i = 0;
    while (list_of_points[i] != NULL) {
        free(list_of_points[i]);
        ++i;
    }
    free(list_of_points);
}
void sort_strings(char** words) {/*сортируем массив в алфавитном порядке */
    int point = 0;
    while (1) {
        if (words[point] != NULL) {
            ++point;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < point; ++i) {
        for (int j = 0; j < point - 1; ++j) {
            if (strcmp(words[i], words[i + 1]) > 0) {
                char* now = words[i];
                words[i] = words[i + 1];
                words[i + 1] = now;
            }
        }
    }
}

int main()
{
    char** p = get_test_strings();
    print_strings(stdout, p);
    free(p);

    char** lines = load_lines("three_little_pigs.txt");
    print_strings(stdout, lines);
    sort_strings(lines);
    print_strings(stdout, lines);
    destroy_strings(lines);
}
