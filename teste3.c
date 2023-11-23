#include <stdio.h>
#include <math.h>
#include <time.h>

#define TERMS 11111

double calculate_parallel_sum();
double calculate_serial_sum();

int main() {
    clock_t start_time, end_time;
    double parallel_sum, serial_sum;

    // Parallel calculation
    start_time = clock();
    parallel_sum = calculate_parallel_sum();
    end_time = clock();

    double parallel_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Maximum number obtained: ");

    // Serial calculation
    start_time = clock();
    serial_sum = calculate_serial_sum();
    end_time = clock();

    double serial_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nRunning time (Parallel): %.6f seconds\n", parallel_time);

    printf("\nRunning time (Serial): %.6f seconds\n", serial_time);

    return 0;
}

double calculate_parallel_sum() {
    double sum = 1.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i < TERMS; ++i) {
        double term = 1.0;
        double factorial = 1.0;

        for (int j = 1; j <= i; ++j) {
            factorial *= j;
            term /= factorial;
        }

        sum += term;
    }

    return sum;
}

double calculate_serial_sum() {
    int N = TERMS;
    int n = N, x;
    int a[TERMS];

    while (--n) {
        a[n] = 1 + 1 / n;
    }

    for (; N > 9; printf("%d", x)) {
        for (n = N--; --n; a[n] = x % n, x = 10 * a[n - 1] + x / n);
    }

    return 0;
}
