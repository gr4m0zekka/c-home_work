

#include <stdio.h>
int main()
{
	char str[50];
	int calc = 0;
	scanf("%s", str);
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '(') {
			++calc;
		}
		else {
			--calc;
		}
		if (calc == -1) {
			break;
		}
	}
	if (calc) {
		printf("No");
	}
	else {
		printf("Yes");
	}
}
