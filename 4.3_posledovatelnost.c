
#include <stdio.h>
#include <limits.h>
int main()
{
	int n, calc = 0;
	scanf_s("%i", &n);
	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf_s("%i", &a);
		if (a > max) {
			max = a;
			calc = 0;
		}
		else if (a = max) {
			calc += 1;
		}
	}
	printf("%i %i", max, calc);
}

