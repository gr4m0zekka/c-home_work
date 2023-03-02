

#include <iostream>
#include <list>

int ruletka(int N, int k) {
	std::list<int> l{1};
	for (int i = 2; i <= N; i++) {
		l.push_back(i);
	}
	int calc = 1;
    while (1) {
		std::list<int>::iterator it = l.begin();
		while (it != l.end()) {
			if (calc == k) {
				std::cout << *it << std::endl;
				if (it != l.end()) {
					it = l.erase(it);
					calc = 1;
				}
				else {
					l.erase(it);
					calc = 1;
				}
			}
			if (it != l.end()) {
				it++;
				calc++;
			}
		}
		if (l.size() == 1)
			break;
	}
	std::list<int>::iterator it = l.begin();
	return *it;
}


int main()
{
	std::cout << ruletka(21, 6) << std::endl;
}

