#include <iostream>
#include <vector>
#include <algorithm>


void shake(std::string& s) {
    std::reverse(s.begin(), s.end());
}

void rev(std::vector<std::string>& str) {
    std::reverse(str.begin(), str.end());
    std::for_each(str.begin(), str.end(), shake);
}

int main()
{
    std::vector<std::string> str{ "cat", "dog", "mouse", "elephant" };
    rev(str);
    for (int i = 0; i < str.size(); i++) {
        std::cout << str[i] << std::endl;
    }
}

