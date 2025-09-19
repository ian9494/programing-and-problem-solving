#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int r;
        scanf("%d", &r);
        int arr[500];

        for (int i = 0; i < r; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, r, sizeof(int), cmp);

        int median = arr[r / 2]; // 中位數
        int sum = 0;
        for (int i = 0; i < r; i++) {
            sum += abs(arr[i] - median);
        }
        printf("%d\n", sum);
    }

    return 0;
}
