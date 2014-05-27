/**
SPOJ problem : FARIDA
classifier : basic linear DP problem.

**/
#include <stdio.h>
#include <iostream>
using namespace std;

long long int max(long long int a, long long int b) {
    return (a>=b)?a:b;
}

int main() {
    int T,N;    // T - test cases, N - number of monsters. both int
    // num[i] is number of coins with i-th monster. long long int.
    // dp[i] is the maximum number of coins prince can acquire following the conditions after he reaches i-th monster.
    long long int num[10001], dp[10001];
    cin >> T;
    for(int j=0;j<T;j++) {
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> num[i];
        }
        dp[0]=num[0];
        dp[1] = max( dp[0], num[1]);
        for(int i=2;i<N;i++){
            dp[i] = max( dp[i-1], num[i] + dp[i-2]);
        }
        cout << "Case " << j+1 << ": " <<  dp[N-1] << endl;
    }
return 0;
}
