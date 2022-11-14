

#include <iostream>
#include <string>
#include <cmath>
namespace myspace { /*создаем пространство имен*/
    void printNTimes(char* str, int n = 10) { /*печатаем строку n раз*/
        for (int i = 0; i < n; i++) {
            std::cout << str << std :: endl;
        }
    }
}

struct Book
{
    char title[100];
    int pages;
    float price;
};

/*функции для работы с структурой Book*/

void addPrice(Book& novel, float x) { /*увеличиваем цену Book на x*/
    novel.price += x;
}

bool isExpensive(const Book& novel) {
    return novel.price > 1000;
}

int cubeV(int a) { /*функция возводит в куб число*/
    return pow(a, 3);
}

int cubeR(int& a) { /*функция возводит в куб число*/
    return pow(a, 3);
}

void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther) { /*считаем количество разных типов символов  в строке*/
    int i = 0;
    while (str[i]) {
        if (str[i] >= 48 && str[i] <= 57) {
            numDigits++;
        }
        else if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) {
            numLetters++;
        }
        else {
            numOther++;
        }
        i++;
    }
}

using namespace std;
int main()
{
    char str[10] = "mugivara"; /*первое задание*/
    myspace :: printNTimes(str );

    int a = 10; /*второе задание*/
    cout << cubeV(a) << endl;

    int& r = a; /*третье задание*/
    cout << cubeR(r) << endl;

    char newstr[20] = "raren0a z0440!!"; /*четвертое задание*/
    int numDigits = 0, numLetters = 0, numOther = 0;
    countLetters(newstr, numLetters, numDigits, numOther);
    cout << "str include " << numLetters << " letters," << numDigits << " numbers," << numOther << " other symbols" << endl;

    Book first;/*пятое задание*/
    strcpy_s(first.title, "one peace");
    first.pages = 1000;
    first.price = 500000000;
    addPrice(first, 1000000000);
    cout << first.price << endl;

    cout << isExpensive(first) << endl; /*шестое задание*/
}

