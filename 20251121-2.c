// quirksome squares - optimized
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int d;
    while (scanf("%d", &d) == 1) {
        int half = d / 2;
        // compute divisor = 10^{half}
        int divisor = 1;
        for (int i = 0; i < half; ++i) divisor *= 10;

        // s = left + right, s ranges 0 .. 2*divisor - 2
        int s_max = 2 * divisor - 2;
        int limit = divisor * divisor; // 10^d
        for (int s = 0; s <= s_max; ++s) {
            long long sq = (long long)s * (long long)s;
            if (sq >= limit) continue; // skip numbers that exceed d digits
            int left = (int)(sq / divisor);
            int right = (int)(sq % divisor);
            if (left + right == s) {
                // print sq with leading zeros to width d
                printf("%0*lld\n", d, sq);
            }
        }
    }
    return 0;
}