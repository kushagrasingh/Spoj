#include <stdio.h>

int power( int i, int k )
{
        if( k <= 0 )
        {       return 1;      }
        int T = 1;
        int j;
                for(j=1; j<=k; j++ )
                {
                    T = T * i;
                }
return T;
}

int main ()
{
    int N;
    int c = 1;
while(1)
    {
        scanf("%d",&N);
        if( N == 0 )
            {   return 0; }
//Case 1, N = 2, # of different labelings = 1
            printf("Case %d, N = %d, # of different labelings = %d\n",c++,N,power(N,N-2));
    }
}
