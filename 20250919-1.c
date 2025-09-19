#include <stdio.h>

int main() {
    int T, count=0, a, b, sum;
    scanf("%d", &T);
    while (T--) {
        sum = 0;
        scanf("%d %d", &a, &b);
        for (int i=a; i<=b; i++) {
            if (i % 2 == 1) {
                sum += i;
            }
        }
        count++;
        printf("Case %d: %d\n", count, sum);
    }
}