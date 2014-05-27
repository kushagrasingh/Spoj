#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
char num[252], dp[32][256],len;

int solve( int pos, int prev ) {
    if( pos == len )
        return 1;
    int ret = dp[pos][prev];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int i=pos,sum=0; i < len; i++) {
        sum += num[i] - '0';
        if(sum >= prev)
            ret += solve(i+1,sum);
    }
return (dp[pos][prev]=ret);
}

int main() {
    int count = 1;
    while(scanf("%s",&num) && isdigit(num[0]) ) {
        memset(dp,-1,sizeof(dp));
        len = strlen(num);
        printf("%d. %d\n",count++,solve(0,0));
    }
    return 0;
}
