#include <stdio.h>
#include <ctype.h>
#include <string.h>

static const char *row1 = "`1234567890-=";
static const char *row2 = "qwertyuiop[]\\";
static const char *row3 = "asdfghjkl;\'";
static const char *row4 = "zxcvbnm,./";

char map_two_left(char ch) {
    // 非字母時直接用小寫去找；最後再依原來大小寫決定輸出
    int is_upper = isupper((unsigned char)ch);
    char low = (char)tolower((unsigned char)ch);

    const char *rows[] = {row1, row2, row3, row4};
    for (int r = 0; r < 4; ++r) {
        const char *p = strchr(rows[r], low);
        if (p) {
            int idx = (int)(p - rows[r]);
            if (idx >= 2) {
                char out = rows[r][idx - 2];
                return is_upper ? (char)toupper((unsigned char)out) : out;
            } else {
                // 左邊不足兩格：照原字回傳
                return ch;
            }
        }
    }
    // 不在表內（空白、換行、其他符號）：原樣
    return ch;
}

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(map_two_left((char)c));
    }
    return 0;
}
