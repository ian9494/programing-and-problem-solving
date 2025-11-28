#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int M, N, Q;
        scanf("%d %d %d", &M, &N, &Q);
        char grid[105][105];
        for (int i = 0; i < M; ++i) {
            scanf("%s", grid[i]);
        }
        printf("%d %d %d\n", M, N, Q);
        for (int qi = 0; qi < Q; ++qi) {
            int r, c;
            scanf("%d %d", &r, &c);
            // input coordinates are 0-based in this problem statement, use as-is
            char ch = grid[r][c];
            int maxSide = 1;
            int k = 1;
            while (1) {
                int r1 = r - k, r2 = r + k, c1 = c - k, c2 = c + k;
                if (r1 < 0 || c1 < 0 || r2 >= M || c2 >= N) break;
                int ok = 1;
                // check vertical borders
                for (int i = r1; i <= r2 && ok; ++i) {
                    if (grid[i][c1] != ch || grid[i][c2] != ch) ok = 0;
                }
                // check horizontal borders
                for (int j = c1; j <= c2 && ok; ++j) {
                    if (grid[r1][j] != ch || grid[r2][j] != ch) ok = 0;
                }
                if (!ok) break;
                maxSide = 2*k + 1;
                k++;
            }
            printf("%d\n", maxSide);
        }
    }
    return 0;
}
