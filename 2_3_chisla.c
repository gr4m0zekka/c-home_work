

#include <iostream>
#include <cmath>


using namespace std;


int main()
{
	int a, b, c;
	scanf_s("%i%i%i", &a, &b, &c);
	if ((b == a + 1 && c == b + 1) || (a == b + 1 || b == c + 1)) {
		printf("Consecutive ");
	}
	if (a < b && b < c) {
		printf("Increasing ");
	}
	else if (a > b && b > c) {
		printf("Decreasing ");
	}
	else if (a == b == c) {
		printf("Equal ");
	}
	else {
		printf("None");
	}
}