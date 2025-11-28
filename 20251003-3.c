#include <stdio.h>

int count_cycle(int n) {
    int count = 1;
    while (n != 1) {
        if (n%2 == 1) n = (3*n)+1;
        else n/=2;
        count++;
    }
    return count;
}


int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int min = a < b ? a : b;
        int max = a > b ? a : b;
        int max_cycle = 0;
        for (int i = min; i <= max; i++) {
            int temp = count_cycle(i);
            if (temp > max_cycle) max_cycle = temp;
        }
        printf("%d %d %d\n", a, b, max_cycle);
    }
}