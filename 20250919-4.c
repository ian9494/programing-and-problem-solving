#include <stdio.h>

int isSquare(int n) {
    if (n < 0) return 0; // 負數不是完全平方數
    int left = 0, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long sq = (long long)mid * mid; // 使用 long long 避免溢位
        if (sq == n) {
            return 1; // 是完全平方數
        } else if (sq < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0; // 不是完全平方數
}

int main() {
    while (1) {
        int a, b, n=0;
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        for (int i = a; i <= b; i++) {
            if (isSquare(i)) {
                n++;
            }
        }
        printf("%d\n", n);
    }
    return 0;
}
