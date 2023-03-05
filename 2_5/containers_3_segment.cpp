#include <iostream>
#include <set>

void rope(int l, int n) {
    std::set<int>  cuts{ 0, l };
    std::multiset <int> length {l};
    int k;
    for (int i = 0; i < n; i++) {
          std::cin >> k;
          cuts.insert(k);
          std::set<int>::iterator it = cuts.find(k);
          it++;
          int right = *it - k;
          it--;
          it--;
          int left = k - *it;
          std::multiset<int>::iterator iti = length.find(left + right);
          length.erase(iti);
          length.insert(right);
          length.insert(left);
          iti = length.end();
          iti--;
          std::cout << *iti << std::endl;
    }
}

int main()
{
    rope(20, 8);
}

