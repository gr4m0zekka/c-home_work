

#include <iostream>
#include <vector>
#include <string>
#include <span>

int sumEven(const std::vector<int>& v) {
	int calc = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			calc += v[i];
		}
	}
	return calc;
}

std::vector<int> lastDigits1(const std::vector<int>& v) {
	std::vector<int> new_v;
	for (int i = 0; i < v.size(); i++) {
		new_v.push_back(v[i] % 10);
	}
	return new_v;
}
void lastDigits2(std::vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] % 10;
	}
}

void lastDigits3(std::vector<int>* pv) {
	for (int i = 0; i < (*pv).size(); i++) {
		(*pv)[i] = (*pv)[i] % 10;
	}
}

/* void lastDigits4(std::span<int> sp) {
	for (int i = 0; i < sp.size(); i++) {
		sp[i] = sp[i] % 10;
	}
} */

std::vector<std::pair<int, int>> factorization(int n) {
	if (n == 1) {
		std::vector<std::pair<int, int>> v;
		v.push_back(std::make_pair(1, 1));
			return v;
	}
	else {
		std::vector<std::pair<int, int>> v;
		int nn = n;
		for (int i = 2; i < sqrt(nn); i++) {
			if (n % i == 0) {
				v.push_back(std::make_pair(i, 0));
			}
			while (n % i == 0) {
				(v.back()).second++;
				n /= i;
			}
		}
		return v;
	}
}

int main()
{
	std::vector<int> vec{ 1, 34, 75, 28, 60 };//проверка первого задания
	std::cout << sumEven(vec) << std::endl;

	std::vector<int> vec1{ 1, 62, 43, 94, 25, 36, 87, 18, 59};//проверка второго задания, пункт 1
	std::vector<int> new_vec1 = lastDigits1(vec1);
	for (int i = 0; i < new_vec1.size(); i++) {
		std::cout << new_vec1[i] << std::endl;
	}

	lastDigits2(vec1);//проверка второго задания, пункт 2
	for (int i = 0; i < vec1.size(); i++) {
		std::cout << vec1[i] << std::endl;
	}

	std::vector<int>* plv = &vec;//проверка второго задания, пункт 3
	lastDigits3(plv);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << std::endl;
	}

	std::vector<std::pair<int, int>> k = factorization(626215995);//проверка третьего задания
	for (int i = 0; i < k.size(); i++) {
		std::cout << k[i].first << " " << k[i].second << std::endl;
	}
}

