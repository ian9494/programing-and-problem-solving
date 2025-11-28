#include <stdio.h>

int val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 36;
    return -1;
}

int main() {
    char n[100];
    while (scanf("%s", n) != EOF) {
        long long sum = 0;
        int mx = -1;
        for (int i = 0; n[i] != '\0'; i++) {
            int v = val(n[i]);
            if (v > 0) {
                sum += v; 
                mx = mx > v ? mx : v;
            }
        }
        
        int start = mx + 1 > 2 ? mx + 1 : 2;
        int ans = -1;
        for (int base = start; base <= 62; base++) {
            if (sum % (base - 1) == 0) {
                ans = base;
                break;
            }
        }
        if (ans == -1) {
            printf("such number is impossible!\n");
        } else {
            printf("%d\n", ans);
        }
    }
}