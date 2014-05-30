#include<stdio.h>
long long int MAX(int a,int b)
{
    if(a>=b)
    return a;
    else
    return b;
}
int main()
{
    typedef enum {false=0, true=1}boolean;
        boolean done = false;
        boolean sNotFound = false;
    long long int N,M,s,x,k=0;
    long long int result = 0;
    long long int total=0;

    scanf("%lld %lld",&N,&M);
    long long int nums[N];
    long long int sums[N];
s = N-1;
int i;
    for(i=0;i<N;i++)
    {
        scanf("%lld",&x);
        total+=x;
            if(x==M || total == M)
            {
                result = M;
                done=true;
            }
            if(x<M && x>result)
            {
                result = x;
            }
            if(total < M && total > result)
            {
                result = total;
            }
            if(total > M && !sNotFound)
            {
                s=i;
                sNotFound = true;
            }
nums[k]=x;
sums[k]=total;
k++;
    }

    if(done)
    {
        printf("%lld\n",result);
    }
    else
    {
        long long int i=s,j=0,max=0;
       long long int mI = i,mJ=0;
            while(i!=N-1 || j!=N-1)
            {
                while(j<N && sums[i]-sums[j]>M)
                {
                    ++j;
                }
                max = MAX(result,sums[i]-sums[j]);
                if(max == M)
                {
                    result=max;
                    break;
                }
                while(i<N && sums[i]-sums[j] <=M)
                {
                    ++i;
                }
                if(i==j)
                {
                    max = sums[i]-sums[j];
                }
                else
                {
                    max = MAX(result,sums[i-1]-sums[j]);
                }
                if(max == M)
                {
                    result=max;
                    break;
                }

                if(mI == i && mJ == j)
                {
                    break;
                }
                else
                {
                    mI = i;
                    mJ=j;
                }
result = MAX(result,max);
            }
    printf("%lld\n",result);
    }
return 0;
}

