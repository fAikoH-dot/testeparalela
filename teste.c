#include <stdio.h>
#include <omp.h>
#include <math.h>

#define TERMS 1000000

int main() {
    double sum = 1.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i < TERMS; ++i) {
        double term = 1.0;
        for (int j = 1; j <= i; ++j) {
            term /= j;
        }
        sum += term;
    }

    printf("Approximation of e with %d terms: %.15f\n", TERMS, sum);

    return 0;
}
