#include <stdio.h>
#include <string.h>

//計算是不是11的倍數 數字最大1000位
int main() {
    char num[1002];
    while (scanf("%s", num) != EOF && strcmp(num, "0") != 0) {
        int len = strlen(num);
        int sum_odd = 0, sum_even = 0;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                sum_odd += num[i] - '0';
            } else {
                sum_even += num[i] - '0';
            }
        }
        int diff = sum_odd - sum_even;
        if (diff % 11 == 0) {
            printf("%s is a multiple of 11.\n", num);
        } else {
            printf("%s is not a multiple of 11.\n", num);
        }
    }
    return 0;
}