#include<iostream>
#include<stdio.h>

using namespace std;

int read()
{unsigned int acc = 0;
register char buf;
buf = getchar_unlocked();
while(buf!=10&&buf<='9'&&buf>='0')
{ acc = acc * 10 + buf - '0';
buf = getchar_unlocked();
}

return(acc);
}

int grid[2000][2000];

int dp[1001];

int area,people;

int main()
{
    int n,m,q,k,i,j,c,x1,x2,y1,y2;
    n=read();
    m=read();
    q=read();
    k=read();
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            grid[i][j]=read();
        }
    }
    for(i=1;i<n;i++)
        grid[i][0] += grid[i-1][0];
    for(j=1;j<m;j++)
        grid[0][j] += grid[0][j-1];
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }
    for(j=0;j<=k;j++)
        dp[j] = 0;
    for(i=0;i<q;i++)
    {
        x1=read();
        y1=read();
        x2=read();
        y2=read();
        area = (x2-x1+1) * (y2-y1+1);
        people = grid[x2-1][y2-1];
        if(y1>1)
            people -= grid[x2-1][y1-2];
        if(x1>1)
            people -= grid[x1-2][y2-1];
        if(x1>1 && y1>1)
            people += grid[x1-2][y1-2];
        for(j=k;j>=people;j--)
        {
                c = dp[j-people] + area;
                if(c>dp[j])
                    dp[j] = c;
        }
    }
    printf("%d\n",dp[k]);
    return 0;
}

