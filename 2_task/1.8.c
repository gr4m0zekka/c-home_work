#include <stdio.h>
int main()
{
	int a[1000];
	int n, k;
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);
	scanf_s("%i", &k);
	for (int i = n - 1; i >= 0; --i) {
		a[(i + k)] = a[i];
	}
	for (int i = 0; i < k; ++i) {
		a[i] = a[n + i];
	}
	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
	printf("\n");
}