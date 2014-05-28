#include<stdio.h>
int main()
 {
int n;
scanf("%d", &n);

int res=0;
for(int i=1;i*i<=n;i++){
res+=n/i-i+1;
}

printf("%d\n", res);

return 0;
