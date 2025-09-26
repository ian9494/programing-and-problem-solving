#include <stdio.h>

int main() {
    int s, d;
    while (scanf("%d %d", &s, &d) != EOF) {
        long long day = 0;
        int group = s;
        while (day < d) {
            day += group;
            if (day >= d) break;
            group++;
        }
        printf("%d\n", group);
    }
}