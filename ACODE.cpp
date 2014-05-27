#include <cstdio>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    char inp[5010];
    int ans[5010], len, i;
    scanf("%s",inp);
    while( strcmp(inp,"0")!= 0 ) {
        len = strlen(inp);
        ans[0]=1;
        ans[1]=1;
        for(i=0;i<len;i++) {
            if ( inp[i] =='0' && (inp[i-1]!='1' && inp[i-1]!='2')) {
                ans[len] = 0;
                break;
            } else if (inp[i] == '0' ) {
                ans[i+1] = ans[i-1];
            } else if ( (inp[i] >= '1' && inp[i] <= '6'&& inp[i-1]=='2') || (inp[i]>='1' && inp[i]<='9' && inp[i-1]=='1' )) {
                ans[i+1] = ans[i] + ans[i-1];
            } else {
                ans[i+1] = ans[i];
            }
        }
        printf("%d\n",ans[len]);
        scanf("%s",inp);
    }
    return 0;
}
