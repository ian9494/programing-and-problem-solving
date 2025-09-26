#include <stdio.h>

#define MAXN 2000
#define MAXL 80

int cmp_str(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}


int main() {
    int n;
    scanf("%d", &n);
    getchar(); // 消除 scanf 後殘留的換行符

    char countries[MAXN][MAXL];
    char line[256];
    int m=0;

    while (n--)
    {
        if (!fgets(line, sizeof(line), stdin) ) break;
        char country[MAXL];
        if (sscanf(line, "%79s", country) == 1) {
            strncpy(countries[m], country, MAXL);
            countries[m][MAXL-1] = '\0';
            ++m;
        }
    }

    qsort(countries, m, sizeof(countries[0]), cmp_str);

    int i=0;
    while (i < m) {
        int count = 1;
        while (i + count < m && strcmp(countries[i], countries[i + count]) == 0) {
            count++;
        }
        printf("%s %d\n", countries[i], count);
        i += count;
    }
    return 0;
}