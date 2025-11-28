#include <stdio.h>
#include <string.h>

#define MLen 1000005

static int a[MLen], b[MLen];

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int tc = 0; tc < T; ++tc) {
        int m;
        if (scanf("%d", &m) != 1) return 0;

        // 清零（初始化 a 與 b）
        // 只需清到 m，但做整段清比較保險
        memset(a, 0, sizeof(int) * (m + 1)); // a[0..m]
        // b 不必保留但為了對應 C++ 我們也讀入後直接累加到 a
        // 讀入並累加
        for (int j = 1; j <= m; ++j) {
            int d1, d2;
            scanf("%d %d", &d1, &d2);
            a[j] = d1 + d2;
        }

        // 處理進位，從最低位往上
        for (int j = m; j > 0; --j) {
            if (a[j] >= 10) {
                a[j-1] += a[j] / 10;
                a[j] %= 10;
            }
        }

        // 輸出（題目要求每個輸出區塊間空行）
        if (tc > 0) putchar('\n');

        if (a[0] == 0) {
            for (int j = 1; j <= m; ++j) putchar('0' + a[j]);
        } else {
            for (int j = 0; j <= m; ++j) putchar('0' + a[j]);
        }
        putchar('\n');
    }
    return 0;
}