#include <stdio.h>

#define MAXN 10000000

int arr[MAXN];

void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);   
        }
        sort(arr, n);

        int left = (n - 1) / 2;
        int right = n / 2;
        int minA = arr[left];
        int maxA = arr[right];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= minA && arr[i] <= maxA) count++;
        }
        printf("%d %d %d\n", minA, count, maxA - minA + 1);
    }
}