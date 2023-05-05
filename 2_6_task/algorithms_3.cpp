#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>

bool chec_sym(std::string str) {
    return std::all_of(str.begin(), str.end(), [](char c) {return !(c >= 97 && c <= 122); });
}

int main()
{
    std::string str{ "CATS AND Dogs12301@!" };
    if (chec_sym(str)) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }
}

