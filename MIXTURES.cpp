#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>

/*
You can split the mixtures set as {m1} and {m2,m3} OR {m1,m2} and {m3}
Let dp[a]][b] = minimum smoke produced on mixing mixtures a to b.

dp[a][b] = MIN[ dp[a][k] + dp[k+1][b] + sum(a,k)*sum(k+1,b) ] ,
for all k where a <= k <= b.
    base case : dp[i][i] = 0.
*/
using namespace std;

int arr[101];
int dp[101][101];

int sum(int a, int b) {
    int sum = 0;
    for(int i=a; i < b+1; i++) {
        sum = sum + arr[i];
        sum %= 100;
    }
    return sum;
}

int solve(int a, int b) {
    if( dp[a][b] != -1 )
        return dp[a][b];
    if( a == b )
        return 0;
    int ret = dp[a][b];

    for( int k=a; k+1<= b;k++) {
        int temp = solve(a,k) + solve(k+1,b) + sum(a,k)*sum(k+1,b);
        if( ret == -1 || temp < ret )
                ret = temp;
    }
    return (dp[a][b]=ret);
}

int main() {
    int n;
    while( cin >> n) {
        for(int i=1;i<n+1;i++) {
            scanf("%d",&arr[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n", solve(1,n) );
    }
    return 0;
}
