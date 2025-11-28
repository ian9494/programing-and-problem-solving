#include <stdio.h>


int first_days[12];

int main() {
    //已知1/10是星期一 先算出每月1號是星期幾
    first_days[0] = 6; //1月1號是星期六
    first_days[1] = (first_days[0] + 31) % 7; //2月1號
    first_days[2] = (first_days[1] + 28) % 7; //3月1號
    first_days[3] = (first_days[2] + 31) % 7; //4月1號
    first_days[4] = (first_days[3] + 30) % 7; //5月1號
    first_days[5] = (first_days[4] + 31) % 7; //6月1號
    first_days[6] = (first_days[5] + 30) % 7; //7月1號
    first_days[7] = (first_days[6] + 31) % 7; //8月1號
    first_days[8] = (first_days[7] + 31) % 7; //9月1號
    first_days[9] = (first_days[8] + 30) % 7; //10月1號
    first_days[10] = (first_days[9] + 31) % 7; //11月1號
    first_days[11] = (first_days[10] + 30) % 7; //12月1號

    int n;
    scanf("%d", &n);
    while (n--) {
        int m, d;
        scanf("%d %d", &m, &d);
        int day_of_week = (first_days[m - 1] + (d - 1)) % 7;
        switch (day_of_week) {
            case 0: printf("Sunday\n"); break;
            case 1: printf("Monday\n"); break;
            case 2: printf("Tuesday\n"); break;
            case 3: printf("Wednesday\n"); break;
            case 4: printf("Thursday\n"); break;
            case 5: printf("Friday\n"); break;
            case 6: printf("Saturday\n"); break;
        }
    }
}