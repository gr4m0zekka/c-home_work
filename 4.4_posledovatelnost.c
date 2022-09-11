

#include <stdio.h>
#include <limits.h>
int main()
{
	int n, now = 1, prev = 1;
	bool flag = true;
	scanf_s("%i", &n);
	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf_s("%i", &a);
		if (i != 0 && i != 1) {
			if (a > max && now == 1) {
				max = a;
				now = 1;
			}
			else if (a < max && now == 2) {
				max = a;
				now = 2;
			}
			else if (a == max && now == 3) {
				now = 3;
			}
			else {
				flag = false;
				break;
			}
		}
		else if (i == 0) {
			max = a;
		}
		else {
			if (a == max) {
				now = 3;
				max = a;
			}
			else if (a > max) {
				now = 1;
				max = a;
			}
			else {
				max = a;
				now = 2;
			}
		}
	}
	if (flag && now == 1) {
		printf(" Increasing");
	}
	else if (flag && now == 2) {
		printf("Decreasing");
	}
	else if (flag && now == 3) {
		printf("Equal");
	}
	else {
		printf("None");
	}
}
