#include<math.h>
#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        long long int n;
        long long int tri;
        scanf("%lld",&n);
        //if((n%2) == 0)
        {
            tri = (n*(n+2)*((2*n)+1))/8;
        }
        /*else if((n%2) != 0)
        {
            tri = ( (n+1)*( (2*pow(n,2)) + (3*n) -1 ))/8;
        }*/
        printf("%lld\n",tri);

        t--;
    }
    return 0;
}

