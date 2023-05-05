#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

template<typename It>
It maxElement(It begin, It end) {
    It maxElem = begin;
    for (It iter = begin; iter != end; ++iter) {
        if (*iter > *maxElem) {
            maxElem = iter;
        }
    }
    return maxElem;
}
int main()
{
    std::vector<int> vec{ 1, 4, 2, 8, 5 }; //проверяем на векторе
    std::vector<int>::iterator vecMax = maxElement(vec.begin(), vec.end());
    std::cout << *vecMax << std::endl;

    std::list<int> lst{ 1, 4, 2, 8, 5 }; //проверяем на списке
    std::list<int>::iterator lstMax = maxElement(lst.begin(), lst.end());
    std::cout << *lstMax << std::endl;

    std::forward_list<int> flst{ 1, 4, 2, 8, 5 }; //проверяем на односвязном списке
    std::forward_list<int>::iterator flstMax = maxElement(flst.begin(), flst.end());
    std::cout <<  *flstMax << std::endl;
}

