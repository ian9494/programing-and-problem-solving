#include <stdio.h>

struct data {
    char name[16];
    int price;
} datas[1000];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int m2 = m;
    while (m2--) {
        scanf("%s %d", datas[m2].name, &datas[m2].price);
    }
    while (n--) {
        // 輸入一段文章 比對字典中的單字 出現就加總價格
        char word[100];
        int total = 0;
        while (scanf("%s", word) == 1 && word[0] != '.') { // 以 '.' 作為結束標誌

            for (int i = 0; i < m; i++) {
                if (strcmp(datas[i].name, word) == 0) {
                    total += datas[i].price;
                    break;
                }
            }
        }
        printf("%d\n", total);
    }
}