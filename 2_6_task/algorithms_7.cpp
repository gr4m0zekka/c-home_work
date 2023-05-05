#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

template <typename It>

void swapNeighbours(It first, It last) {
    if (first == last || std::next(first) == last) {
        return;
    }
    auto iter = first;
    while (iter != last && std::next(iter) != last) {
        std::swap(*iter, *std::next(iter));
        iter = std::next(std::next(iter));
    }
}

int main() {
    std::vector<int> vec{ 1, 2, 3, 4, 5 }; //проверяем на vector
    swapNeighbours(vec.begin(), vec.end());
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::list<int> lst{ 1, 2, 3, 4, 5, 6 };// проверяем на list
    swapNeighbours(lst.begin(), lst.end());
    for (auto elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::forward_list<int> flst{ 1, 2, 3, 4, 5, 6 }; //проверяем на forward_list
    swapNeighbours(flst.begin(), flst.end());
    for (auto elem : flst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}