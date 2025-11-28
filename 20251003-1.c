# include <stdio.h>

// 將輸入的文字逆時針轉90度
int main() {
    char ch;
    char line[100][100];
    int row = 0, col = 0, maxCol = 0;

    // 讀取輸入直到 EOF
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            line[row][col] = '\0'; // 結束當前行
            if (col > maxCol) maxCol = col; // 更新最大列數
            row++;
            col = 0; // 重置列數
        } else {
            line[row][col++] = ch; // 儲存字元並增加列數
        }
    }
    line[row][col] = '\0'; // 結束最後一行
    if (col > maxCol) maxCol = col; // 更新最大列數

    // 輸出順時針轉90度的結果
    for (int c = 0; c < maxCol; c++) {
        for (int r = row - 1; r >= 0; r--) {
            if (c < strlen(line[r])) {
                putchar(line[r][c]);
            } else {
                putchar(' '); // 補齊空格
            }
        }
        putchar('\n'); // 換行
    }

    return 0;
}