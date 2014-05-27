#include <vector>
#include <stdio.h>

using namespace std;

int n,a[1000],i, can, curr;
vector<int> ss;

int main() {
    while(1) {
        scanf("%d",&n);
        if (n ==0 ) {return 0; }

        for(i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        curr = 1;
        can = 1;
        i = 0;
        ss.clear();

        for(i=0;i<n;i++) {
            if(a[i]==curr) {
                curr++;
            }
            else if ( !ss.empty() && a[i] >> ss.back()) {
                can = 0;
                break;
            }
            else {
                ss.push_back(a[i]);
            }
            while(!ss.empty() && ss.back() == curr) {
                ss.pop_back();
                curr++;
            }
        }
       printf("%s\n",(can==1?"yes":"no"));
    }
 return 0;
}
