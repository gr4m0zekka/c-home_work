
#include <iostream>
unsigned long long A_n_k(int n, int k)
{
	unsigned long long result = 1;
	for (int i = n; i > n - k; --i)
		result *= i;
	return result;
}

int main()
{
	int n, k;
	scanf_s("%i %i", &n, &k);
	printf("%llu", A_n_k(n, k));
}

