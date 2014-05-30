#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0 ) { break;    }
        int z = (n*(n+1)*((2*n)+1))/6;
        printf("%d\n",z);
    }
return 0;
}
