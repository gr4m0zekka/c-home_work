#include <string>
#include <iostream>
#include <string_view>

std::string change(std::string a) {
    if (a[0] >= 65 && a[0] <= 90) {
        a[0] += 32;
    }
    else if (a[0] >= 97 && a[0] <= 122) {
        a[0] -= 32;
    }
    return a;
}

 std::string repeat1(std::string_view s) {
    std::string new_s{s};
    new_s += new_s;
    return new_s;
} 

void repeat2(std::string& s) {
    s += s;
}

void repeat3(std::string* s) {
    *s += *s;
}
std::string* repeat4(std::string_view s) {
    std::string* new_s = new std::string[s.size()];
    *new_s  = std::string(s);
    *new_s += *new_s;
    return new_s;
}

std::string operator * (std::string s, int n) {
    std::string new_s = s;
    for (int i = 0; i < n - 1; i++) {
        new_s += s;
    }
    return new_s;
}

void truncateToDot(std::string& s) {
    std::string now = "";
    int i = 0;
    while (s[i] != 46) {
        now += s[i];
        i++;
    }
    s = now;
}

 int sumofstr(std::string str) {
    int time = 0;
    int now = 0;
    int calc = 0;
    while (now < str.size()) {
        if (str[time] >= 48 && str[time] <= 57) {
            while (str[now] != ',') {
                now++;
                if (str[now] == ']') {
                    break;
                }
            }
            for (int i = time; i < now; i++) {
                calc += (str[i] - '0') * pow(10, now - i - 1);
            }
            time = now;
        }
        else {
            time++;
            now++;
        }
    }
    return calc;
}




int main()
{
    std::cout << change("cat") << std::endl; //тестируем первое задание
    std::cout << repeat1("cat") << std::endl; // тестируем второе задание 
    std::string s = "cat";
    repeat2(s);
    std::cout << s << std::endl;
    std::string k = "cat";
    std::string* c  = &k;
    repeat3(c);
    std::cout << *c << std::endl;
    std::cout << *repeat4("cat") << std::endl;
    std::cout << s * 5 << std::endl; //тестируем третье задание
    std::string big_str = "dog.cat.lion.mouse.tiger.aleksanddr_ptitsyn.bird"; //тетсируем четвертое задание
    truncateToDot(big_str);
    std::cout << big_str << std::endl;

    std::cout << sumofstr("[10, 20, 0, 25]") << std::endl; //тестируем шестое задание 

     int* n = new int(123); // тестируем шестое задание
    std::cout << *n << std::endl;
    delete n;
    std::string* str = new std::string("cat and dog");
    std::cout << *str << std::endl;
    delete str;
    int* massiv_n = new int[5]{10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        std::cout << massiv_n[i] << std::endl;
    }
    delete[] massiv_n; 
    std::string* massiv_s = new std::string[3]{ "cat", "dog", "mouse" };
    for (int i = 0; i < 3; i++) {
        std::cout << massiv_s[i] << std::endl;
    }
    

    std::string_view* massiv_v = new std::string_view[3]{ std::string_view{massiv_s[0]},  std::string_view{massiv_s[1]},  std::string_view{massiv_s[2]}};
    for (int i = 0; i < 3; i++) {
        std::cout << massiv_v[i] << std::endl;
    }
    delete[] massiv_v;
}

