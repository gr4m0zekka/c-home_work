#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);
	int new_e, pos;
	scanf_s("%i %i", &new_e, &pos);
	for (int i = 0; i < pos; ++i) {
		a[n - i] = a[n - i - 1];
	}
	a[pos] = new_e;
	++n;
	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
	printf("\n");
}