#include <stdio.h>

int main(){
    while (1)
    {
        int a, b, count=0;
        int a_sep[10]={0}, b_sep[10]={0};

        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        int i=0;
        while (a != 0)
        {
            a_sep[i] = a % 10;
            a /= 10;
            i++;
        }
        i=0;
        while (b != 0)
        {
            b_sep[i] = b % 10;
            b /= 10;
            i++;
        }
        for (int i = 0; i < 10; i++)
        {
            if (a_sep[i] + b_sep[i] >= 10) count++;
        }
        if (count == 0) printf("No carry operation.\n");
        else if (count == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n", count);

    }
    
}