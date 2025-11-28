// hartals
#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int D, p;
        scanf("%d", &D);
        scanf("%d", &p);
        int pi[100];
        for (int i = 0; i < p; i++) {
            scanf("%d", &pi[i]);
        }

        int hartal_days[3650] = {0}; // days are 1-indexed, so we use 1..D
        for (int i = 0; i < p; i++) {
            int interval = pi[i];
            for (int day = interval; day <= D; day += interval) {
                // Skip Fridays (6th day of the week) and Saturdays (7th day of the week)
                if (day % 7 == 6 || day % 7 == 0) {
                    continue;
                }
                hartal_days[day - 1] = 1; // mark hartal day
            }
        }

        int total_hartals = 0;
        for (int day = 0; day < D; day++) {
            if (hartal_days[day]) {
                total_hartals++;
            }
        }
        printf("%d\n", total_hartals);
    }
}