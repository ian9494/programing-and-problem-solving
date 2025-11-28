// check if digit can be divide by 9 and print 9-degree
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int can_divide_by_9(const char *num_str) {
    int sum = 0;
    for (size_t i = 0; i < strlen(num_str); ++i) {
        sum += num_str[i] - '0';
    }
    return (sum % 9 == 0);
}

int main(void) {
    char num_str[1005];
    while (scanf("%s", num_str) == 1) {
        if (strcmp(num_str, "0") == 0) break;
        if (can_divide_by_9(num_str)) {
            int degree = 0;
            char temp_str[1005];
            strcpy(temp_str, num_str);
            while (strlen(temp_str) > 1) {
                int sum = 0;
                for (size_t i = 0; i < strlen(temp_str); ++i) {
                    sum += temp_str[i] - '0';
                }
                sprintf(temp_str, "%d", sum);
                degree++;
            }
            if (degree == 0) degree = 1; // single digit 9 has degree 1
            for (size_t i = 0; i < strlen(num_str); ++i) {
                printf("%c", num_str[i]);
            }
            printf(" is a multiple of 9 and has 9-degree %d.\n", degree);
        } else {
            for (size_t i = 0; i < strlen(num_str); ++i) {
                printf("%c", num_str[i]);
            }
            printf(" is not a multiple of 9.\n");
        }
    }
    return 0;
}