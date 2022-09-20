#include <stdio.h>
int main()
{
	int a[1000];
	int n, new_n;
	scanf_s("%i", &n);
	new_n = n;
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);
	n *= 2;
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < new_n - i / 2; ++j) {
			a[new_n + i / 2 - j] = a[new_n + i / 2 - j - 1];
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
	printf("\n");
}
