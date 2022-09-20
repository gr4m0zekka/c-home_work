#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);
	int pos;
	scanf_s("%i", &pos);
	for (int i = 0; i < n - pos; ++i) {
		a[pos + i] = a[pos + i + 1];
	}
	--n;
	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
	printf("\n");
}