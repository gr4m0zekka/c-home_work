
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>

void move_probel(std::string& str) {
    std::partition(str.begin(), str.end(), [](char c) {return c != 32; });
}
int main()
{
    std::string str{"gogs and cats"};
    move_probel(str);
    for (int i = 0; i < str.size(); i++)
        std::cout << str[i] << std::endl;
}

