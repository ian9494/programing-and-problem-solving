#include <stdio.h>
#include <stdint.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        long long s, d;
        if (scanf("%lld %lld", &s, &d) != 2) break;

        /* 檢查條件：s 與 d 同奇偶，且 s >= d，且 (s+d)/2, (s-d)/2 非負 */
        if (s < d || ((s + d) & 1)) {
            printf("impossible\n");
            continue;
        }

        long long a = (s + d) / 2;
        long long b = (s - d) / 2;
        if (a < 0 || b < 0) {
            printf("impossible\n");
            continue;
        }

        /* 題目要求最大分數先列 */
        printf("%lld %lld\n", a, b);
        // if (a >= b) printf("%lld %lld\n", a, b);
        // else printf("%lld %lld\n", b, a);
    }
    return 0;
}