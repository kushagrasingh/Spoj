#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int findPairs( int arr[], int N, int M) {
    int count=0;
    if( N < 1 )
        return 0;
    int high = N-1;
    int low = 0;

    while( high > low ) {
        int sum = arr[low] + arr[high];
        if(sum == M) {
            count++;
            high--;
            low++;
        } else if( sum > M ) {
            high--;
        } else if (sum < M ) {
            low++;
        }
    }
    return count;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N,M;
        scanf("%d %d",&N,&M);
        int arr[N];
        for(int i=0;i<N;i++) {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+N);
        printf("%d\n",findPairs(arr, N,M));
    }
 return 0;
}
