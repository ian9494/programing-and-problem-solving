#include <stdio.h>

int main() {
    int v,t;
    while (scanf("%d %d", &v, &t) == 2) {
        int distance = v * t * 2;
        printf("%d\n", distance);
    }
}