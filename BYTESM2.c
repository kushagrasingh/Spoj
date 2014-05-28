#include<stdio.h>
int max(int a,int b,int c)
{
    int m=(a>b)?a:b;
    m = (m>c)?m:c;
    return m;
}
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
    int r,c;
    scanf("%d %d",&r,&c);
    int arr[r][c];
    int d[r][c];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
                if(i==0)
                    d[i][j] = arr[i][j];
                else if(j==c-1)
                    d[i][j]=arr[i][j]+max(d[i-1][j],d[i-1][j-1],0);
                else if(j==0)
                    d[i][j] = arr[i][j] + max(d[i-1][j],d[i-1][j+1],0);
                else
                    d[i][j] =arr[i][j] + max(d[i-1][j],d[i-1][j-1],d[i-1][j+1]);
        }
    }

int max=0;
for(j=0;j<c;j++)
{
    if(d[r-1][j] > max)
        max = d[r-1][j];
}
printf("%d\n",max);
}
return 0;
}

