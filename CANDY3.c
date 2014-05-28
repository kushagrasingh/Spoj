#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long int n;
        scanf("%lld",&n);
        long long int sum=0,i;
        for(i=0;i<n;i++)
        {
            long long int next;
            scanf("%lld",&next);
            sum  = (sum+next)%n;
            //printf("%lld sum=%lld\n",i,sum);
        }
            if(sum == 0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
    }
    return 0;
}
