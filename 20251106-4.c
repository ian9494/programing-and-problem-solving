#include <stdio.h>

#define MAX_SIZE 3000

void sort_int_array(int* arr, int size) {
    // Simple bubble sort for demonstration; replace with a more efficient sort if needed
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int arr[MAX_SIZE];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        int arr2[MAX_SIZE-1];
        for (int i = 0; i < n - 1; ++i) {
            arr2[i] = arr[i] - arr[i + 1];
            if (arr2[i] < 0) arr2[i] = -arr2[i];
        }
        sort_int_array(arr2, n - 1);

        // check jolt differences
        int valid = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (arr2[i] != i + 1) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
}