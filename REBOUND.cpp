#include<stdio.h>
#include<math.h>
int main()
{
long int T;
scanf("%ld",&T);
while(T--)
{
    long long  int x,y,z;
   scanf("%lld %lld %lld",&x,&y,&z);
    double D = sqrt(x*x + y*y + 2*z*y);
    double R1;
    if(D == (long long int)D)
    {
            R1 = z*(D+x)/(y+2*z);

                if((R1)==(long long int)R1)
                {
                    if(R1 <= x)
                    {
                    printf("%lld\n",(long long int)R1);
                    continue;
                    }
                    else
                    {
                        printf("Not this time.\n");
                    continue;
                    }
                }
                else
                {
                    printf("Not this time.\n");
                    continue;
                }
    }
        else
        {
        printf("Not this time.\n");
        }
}
return 0;
}

