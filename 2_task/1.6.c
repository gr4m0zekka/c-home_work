#include <stdio.h>
int main()
{
	int a[1000];
	int n, now, k = 0;
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);
	for (int i = 0; i < n; ++i) {
		if (a[k] % 2 == 1) {
			++k;
		}
		else {
			a[n] = a[k];
			for (int j = k; j < n + 1; ++j) {
				a[j] = a[j + 1];
			}
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
	printf("\n");
}