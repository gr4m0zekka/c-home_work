#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>


bool isIdintifier(std::string str) {
    if (str[0] < 48 || str[0] > 57) {
        return std::all_of(str.begin(), str.end(), [](char c) {return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95 || (c >= 48 && c <= 57); });
    }
    else {
        return 0;
    }
}


int main()
{
    std::string str{ "_123isIdetifier" };
    if (isIdintifier(str)) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }
}

