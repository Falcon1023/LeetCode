#include <stdio.h>

char map[10][10];
int main()
{
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
           scanf("%c",&map[i][j]);
        }
        getchar();
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (map[i][j] == '.') {
                int num = 0;
                for (int k=j-1; k>=0 && map[i][k] == 'X'; k--) num++;
                for (int k=j+1; k<10 && map[i][k] == 'X'; k++) num++;
                if (num >= 4) {
                    printf("YES\n");
                    return 0;
                }
                num = 0;
                for (int k=i-1; k>=0 && map[k][j] == 'X'; k--) num++;
                for (int k=i+1; k<10 && map[k][j] == 'X'; k++) num++;
                if (num >= 4) {
                    printf("YES\n");
                    return 0;
                }
                num = 0;
                for (int k=i-1,l=j-1; k>=0 && l>=0 && map[k][l] == 'X'; k--,l--) num++;
                for (int k=i+1,l=j+1; k<10 && l<10 && map[k][l] == 'X'; k++,l++) num++;
                if (num >= 4) {
                    printf("YES\n");
                    return 0;
                }
                num = 0;
                for (int k=i-1,l=j+1; k>=0 && l<10 && map[k][l] == 'X'; k--,l++) num++;
                for (int k=i+1,l=j-1; k<10 && l>=0 && map[k][l] == 'X'; k++,l--) num++;
                if (num >= 4) {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}
