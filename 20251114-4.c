#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int M;
        scanf("%d", &M);
        int x1=M; //x1 decimal, x2 hex
        // 將M當作16進位轉換為10進位 寫入x2
        int x2=0, base=1, temp=M;
        while (temp > 0) {
            int digit = temp % 10;
            x2 += digit * base;
            base *= 16;
            temp /= 10;
        }

        // 將x1和x2轉換為二進位表示 其中x2為16進位
        int bin1[32], bin2[32];
        for (int i = 0; i < 32; i++) {
            bin1[i] = x1 % 2;
            x1 /= 2;
            bin2[i] = x2 % 2;
            x2 /= 2;
        }

        int b1=0, b2=0;
        for (int i = 0; i < 32; i++) {
            if (bin1[i] == 1) b1++;
            if (bin2[i] == 1) b2++;
        }

        // M xor (b1*b2)
        printf("%d %d\n", b1, b2);
    }
}