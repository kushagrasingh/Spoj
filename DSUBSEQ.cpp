/* Problem : DSUBSEQ Spoj
Dynamic programming
Let dp[i] be number of distinct subsequences ending with str[i]
ans[i] = dp[1] + dp[2] + ...... + dp[i]
ans[i] represents the total number of distinct subsequences,
when considering the first i characters of string.

prev[i] position of last occurrence of character str[i]
base case: dp[0] = 0 ans[0] =0

We can append str[i] to all previously found sunsequences. But in that case, those subsequences
which had previous str[i] appended to them will be considered twice, so subtract them.

dp[i] = ans[i-1] - and[ prev[str[i]-1 ]
ans[i] = ans[i-1] + dp[i]

prev[ str[i] ] = i

Finally, ans[n] is the answer we need.
*/

#include <iostream>
#include<stdio.h>
#include <cstring>

using namespace std;

const long long MOD=1000000007;

long long sum[26];

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        string s;
        cin>>s;
        int n=s.size();

        memset(sum,0,sizeof(sum));

        sum[s[0]-'A']=1;
        long long ret=2;

        for(int i=1;i<n;i++) {
            int idx=s[i]-'A';
            long long tmp = ( ret - sum[idx] + MOD) % MOD;
            ret = ( ret + tmp ) % MOD;
            sum[idx] = ( sum[idx] + tmp) % MOD;
        }
      cout<<ret<<endl;
    }
return 0;
}
