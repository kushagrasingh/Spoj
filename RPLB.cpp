#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int N,K,wt[1001],dp[1001][1001];

int max(int a, int b){
    return (a>=b)?a:b;
}

int solve(int i, int w) {
    if( i > N )
        return w;
    if( dp[i][w]!=-1)
        return dp[i][w];
    if(wt[i]+w <= K)
        dp[i][w] = max( solve(i+2,w+wt[i]), solve(i+1,w));
    else
        dp[i][w] = solve(i+1,w);

return dp[i][w];
}


int main() {
    int T,count=1;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&N,&K);
        for(int i=1;i<=N;i++) {
            scanf("%d",&wt[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("Scenario #%d: %d\n",count++,solve(1,0));
    }
return 0;
}
