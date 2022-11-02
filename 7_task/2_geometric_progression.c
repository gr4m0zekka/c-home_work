#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

float* get_geometric_progression(float a, float r, int n) {
    float* progression = (float*)malloc(sizeof(float) * n);
    progression[0] = a;
    for (int i = 1; i < n; ++i) {
        progression[i] = progression[i - 1] * r;
    }
    return progression;
}
int main()
{
    float a, r;
    scanf("%f %f", &a, &r);
    int n;
    scanf("%i", &n);
    float* new_p = get_geometric_progression(a, r, n);
    for (int i = 0; i < n; ++i) {
        printf("%.0f ", new_p[i]);
    }
    free(new_p);
}

