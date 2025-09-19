#include <stdio.h>

int count[26];

int main() {
    int T;
    scanf("%d", &T);
    getchar(); // 消除 scanf 後殘留的換行符
    while (T--) {
        char str[1000];
        fgets(str, 1000, stdin);
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                count[str[i] - 'a']++;
            }
            else if (str[i] >= 'A' && str[i] <= 'Z') {
                count[str[i] - 'A']++;
            }
        }
        
    }
    // sort and print results

    char letters[26];

    for (int i = 0; i < 26; i++) {
        letters[i] = 'A' + i;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (count[j] > count[i] || (count[j] == count[i] && letters[j] < letters[i])) {
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;

                char tempChar = letters[i];
                letters[i] = letters[j];
                letters[j] = tempChar;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c %d\n", letters[i], count[i]);
        }
    }
}