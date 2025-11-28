#include <stdio.h>
#include <string.h>

int main(void) {
    static char s[10005], t[10005];
    while (scanf("%s %s", s, t) == 2) {
        int len_s = (int)strlen(s);
        int len_t = (int)strlen(t);

        // two-pointer subsequence check
        int i = 0, j = 0;
        while (i < len_t && j < len_s) {
            if (t[i] == s[j]) {
                j++;
            }
            i++;
        }

        if (j == len_s) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}