#include <stdio.h>
const int N = 1024;

int main()
{
    int b[N];
    int cnum,n,z;
    for(cnum = 0; scanf("%d", &n) == 1 && n; ){
            int sum = 0;
            int i,j;
            for(i=0;i<n;i++)
            {
                b[i] = 0;
            }
                for(i=0;i<n;i++)
                    for(j=0;j<n;j++)
                {
                    scanf("%d", &z);
                    if(z)
                    {
                        b[j] += z;
                        b[i] -= z;
                        sum += z;
                    }
                }
            printf("%d. %d ", ++cnum, sum);
            sum = 0;
                for(i=0;i<n;i++)
                    if(b[i] > 0) sum += b[i];
                printf("%d\n", sum);
        }
return 0;
}

