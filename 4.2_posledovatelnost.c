
#include <stdio.h>
#include <limits.h>
int main()
{
	int n;
	scanf_s("%i", &n);
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf_s("%i", &a);
		if (a > max && a % 2 == 1) {
			max = a;
		}
		if (a < min && a % 2 == 0) {
			min = a;
		}
	}
	if (min == INT_MAX) {
		printf("None");
	}
	else {
		printf("%i ", min);
	}
	if (max == INT_MIN) {
		printf("None");
	}
	else {
		printf("%i ", max);
	}
}