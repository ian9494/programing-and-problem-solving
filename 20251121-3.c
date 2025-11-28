// Decimal to Fibonacci Base
#include <stdio.h>
#include <stdlib.h>

void generate_fib_up_to(int max, int **fib_ptr, int *fib_count_ptr) {
    int *fib = (int *)malloc(50 * sizeof(int));
    fib[0] = 1;
    fib[1] = 2;
    int count = 2;
    while (1) {
        int next_fib = fib[count - 1] + fib[count - 2];
        if (next_fib > max) break;
        fib[count++] = next_fib;
    }
    *fib_ptr = fib;
    *fib_count_ptr = count;
}

int main(void) {
    int max_n = 1000000000; // 10^9
    int *fib;
    int fib_count;
    generate_fib_up_to(max_n, &fib, &fib_count);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int n2=n; // store original n for output
        if (n == 0) {
            printf("0\n");
            continue;
        }
        char result[100] = {0};
        int pos = 0;
        int started = 0; // flag to indicate if we've started adding to result
        for (int i = fib_count - 1; i >= 0; --i) {
            if (fib[i] <= n) {
                n -= fib[i];
                result[pos++] = '1';
                started = 1;
            } else if (started) {
                result[pos++] = '0';
            }
        }
        result[pos] = '\0';
        printf("%d = %s (fib)\n", n2, result);
    }
    free(fib);
    return 0;
}