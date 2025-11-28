#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int count=1;
    while (n--) {
        char s1[50], s2[50];
        scanf("%s %s", s1, s2);
        // 將二進制字串轉換為十進制整數
        int num1 = 0, num2 = 0;
        for (int i = 0; s1[i] != '\0'; i++) {
            num1 = num1 * 2 + (s1[i] - '0');
        }
        
        for (int i = 0; s2[i] != '\0'; i++) {
            num2 = num2 * 2 + (s2[i] - '0');
        }

        // 求兩數有沒有公因數
        int a = num1, b = num2;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        if (a > 1) {
            printf("Pair #%d: All you need is love!\n", count++);
        } else {
            printf("Pair #%d: Love is not all you need!\n", count++);
        }
    }
}