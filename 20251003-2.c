#include <stdio.h>
// 將將輸入的數字轉二進制 然後計算 1 的個數

int main() {
    int n;
    int binary[32]; // 假設最多 32 位元

    while (scanf("%d", &n) != EOF && n != 0) {
        int count = 0, highest = 0;
        int temp = n;
        for (int i = 0; i < 32; i++) {
            binary[i] = temp % 2;
            temp /= 2;
            if (binary[i] == 1) count++;
            if (temp == 0) {
                highest = i;
                break;
            }
        }
        printf("The parity of ");
        for (int i = highest; i >= 0; i--) {
            printf("%d", binary[i]);
        }
        printf(" is %d (mod 2).\n", count);
    }
    return 0;
}