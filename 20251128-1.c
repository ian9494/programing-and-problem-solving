#include <stdio.h>

long long get_ID(long long x, long long y) {
    long long d = x + y;
    long long ID = d * (d + 1) / 2 + x;
    return ID;
}

int main() {
    long long x1, y1, x2, y2;
    int t, case_num = 1;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        if (scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2) != 4) break;
        long long ID1 = get_ID(x1, y1);
        long long ID2 = get_ID(x2, y2);
        printf("Case %d: %lld\n", case_num++, ID2 - ID1);
    }
    return 0;
}