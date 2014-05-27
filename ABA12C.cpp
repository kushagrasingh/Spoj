#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n,k, packs[100], ans[101], no[101], t, i , j, cost, l;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        for(j=0;j<k;j++){
            scanf("%d",&packs[i]);
        }
        ans[0]=0;
        no[0]=0;
        for(j=1;j<=k;j++){
            ans[j]=1;
            no[j]=1;
                for(l=0;l<j;l++){
                    if (packs[l] != -1 && ans[j-l-1]!=-1 && no[j-l-1] < n) {
                        cost = ans[j-l-1] + packs[l];
                        if(ans[j]==-1 || ans[j]>cost){
                            ans[j] = cost;
                            no[j] = no[j-1] + 1;
                        }
                    }
                }
        }
        printf("%d\n",ans[k]);
    }
return 0;
}
