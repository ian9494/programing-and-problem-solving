// Bangla number (fixed implementation)

#include <stdio.h>
#include <stdlib.h>

// Print a positive number n in Bangla grouping without leading/trailing spaces
// Uses recursive decomposition by "kuti" blocks (10^7)
void print_bangla(long long n, int need_space) {
    if (n == 0) return;

    const long long KUTI = 10000000LL; // 10^7
    if (n >= KUTI) {
        // print higher kuti blocks first
        print_bangla(n / KUTI, need_space);
        if (need_space) putchar(' ');
        printf(" kuti");
        need_space = 1;
        n %= KUTI;
    }

    // parts within one kuti: lakh(10^5), hajar(10^3), shata(10^2), remainder
    long long lakh = n / 100000LL; // 10^5
    if (lakh) {
        if (need_space) putchar(' ');
        printf("%lld lakh", lakh);
        need_space = 1;
    }
    n %= 100000LL;

    long long hajar = n / 1000LL;
    if (hajar) {
        if (need_space) putchar(' ');
        printf("%lld hajar", hajar);
        need_space = 1;
    }
    n %= 1000LL;

    long long shata = n / 100LL;
    if (shata) {
        if (need_space) putchar(' ');
        printf("%lld shata", shata);
        need_space = 1;
    }
    n %= 100LL;

    if (n) {
        if (need_space) putchar(' ');
        printf("%lld", n);
    }
}

int main(void) {
    long long n;
    int case_num = 1;
    while (scanf("%lld", &n) == 1) {
        if (n == 0) {
            printf("0\n");
            continue;
        }
        printf("%d. ", case_num++);
        print_bangla(n, 0);
        putchar('\n');
    }
    return 0;
}