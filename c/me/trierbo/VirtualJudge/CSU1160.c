#include <stdio.h>
 
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        char ch[8];
        for (int i = 7; i >= 0; i--)
        {
            int t = n % 16;
            n /= 16;
            if (t < 10)
              ch[i] = '0' + t;
            else
              ch[i] = 'A' + t - 10;
        }
        printf("%s", "0x");
        for (int i = 0; i < 8; i++)
          printf("%c", ch[i]);
        printf("\n");
    }
    return 0;
}
