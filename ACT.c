#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
while(t>0)
{
    int n,i;
    scanf("%d",&n);
    char x,y;
    x='a';
    while(x != '\n')
    {
        y = x;
        scanf("%c",&x);
    }
        printf("%c\n",y);

    t--;
}
    return 0;
}
