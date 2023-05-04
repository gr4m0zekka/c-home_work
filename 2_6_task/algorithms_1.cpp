#include <iostream>
#include <vector>
#include <algorithm>


void mautain(std::vector<int>& num) {
    std::vector<int>::iterator it = std::max_element(num.begin(), num.end());
    std::sort(num.begin(), it);
    std::sort(it, num.end());
    std::reverse(it, num.end());
}
int main()
{
    std::vector<int> num{ 5,2,1,5,6,8,6,4,3,8 };
    mautain(num);
    for (int i = 0; i < 10; i++) {
        std::cout << num[i] << std::endl; 
    }
}

