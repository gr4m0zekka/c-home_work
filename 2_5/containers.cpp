
#include <iostream>
#include <list>


int ruletka(std::list<int>& l, int k) {
	int start;
	int end = 0;
	while (l.size() > 1) {
		start = k - end;
		int i = 1;
		std::list<int>::iterator it = l.begin();
		while (i < start) {
			i++;
			++it;
		}
		i = 1;
		while (it != l.end()) {
			std::cout << *it << std::endl;
			it = l.erase(it);
			end = 0;
			i = 1;
			while (i < k) {
				i++;
				if (it != l.end()) {
					++it;
				}
				else {
					break;
				}
				end++;
			}
		}
	}
	std::list<int>::iterator it = l.begin();
	return *it;
}

int main()
{
	std::list<int> l {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
	std::cout << ruletka(l, 6) << std::endl;
}

