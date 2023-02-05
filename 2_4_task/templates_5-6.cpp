#include <iostream>
#include <vector>
#include <string>
#include <span>

template <typename T>
T vecMax(std::vector<T>& v) {
	T max = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > v[i - 1]) {
			max = v[i];
		}
	}
	return max;
}

template <typename container>
std::vector<std:: pair<typename container:: value_type, typename container::value_type >> pairs(container& cont) {
	std::vector<std::pair<typename container::value_type, typename container::value_type>> V;
	for (int i = 0; i < cont.size(); i += 2) {
		std::pair<typename container::value_type, typename container::value_type> p;
		p.first = cont[i];
		if (i + 1 > cont.size()) {
			p.second = typename container::value_type();
		}
		else {
			p.second = cont[i + 1];
		}
		V.push_back(p);
	}
	return V;
}


int main()
{
	std::vector<int> V_0{ 1, -5, 20, 60 };//проверяем 5 задание
	std::vector<float> V_1 { 0,011, -5,67, 20,32, -60,32, 53,0 };
	std::vector<std::string> V_2{ "cat", "barbeque", "cheese burger" };
	std::vector<std::pair<int, int>> V_3 { {10, 15}, { 23,17 }, { 4,98 }, { 67,5 }};
	std::cout << vecMax<int>(V_0) << std::endl;
	std::cout << vecMax<float>(V_1) << std::endl;
	std::cout << vecMax<std::string>(V_2) << std::endl;
	std::pair<int, int> res_3 = vecMax<std::pair<int, int>>(V_3);
	std::cout << res_3.first << ' ' << res_3.second << std::endl;

	std::vector<int> V_4 { 1,2,3,4,5,6 };//проверяем шестое задание, чтобы хотя бы без ошибок компилировалось
	std::vector<std::pair<int, int>> new_v4 = pairs(V_4);
	for (int i = 0; i < new_v4.size(); i++) {
		std::cout << new_v4[i].first << " " << new_v4[i].second << std::endl;
	}
}