#include <iostream>
#include <map>

void uniqueN(int n, const int k[]) {
    std::map<int, int> un;;
    std::map<int, int>::iterator it = un.begin();
    for (int i = 0; i < n; i++) {
        it = un.find(k[i]);
        if (it == un.end()) {
            un.insert({ k[i], 1});
        }
        else {
           it -> second++;
        }
    }
   
    for (std::map<int, int>::iterator it = un.begin(); it != un.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}
int main()
{
    int a[10] = { 5,1,5,1,1,1,2,1,5,1 };
    uniqueN(10, a);
}

