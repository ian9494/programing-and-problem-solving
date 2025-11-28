// check if n is prime or emirp
#include <stdio.h>
#include <math.h>

int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    int limit = (int)sqrt((double)n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int reverse_number(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int main(void) {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) break;
        int prime = is_prime(n);
        int rev = reverse_number(n);
        int rev_prime = is_prime(rev);
        if (prime && rev_prime && rev != n) {
            printf("%d is emirp.\n", n);
        } else if (prime) {
            printf("%d is prime.\n", n);
        } else {
            printf("%d is not prime.\n", n);
        }
    }
    return 0;
}