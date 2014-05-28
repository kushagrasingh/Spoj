#include<stdio.h>

    unsigned int arr[1000000]={0};
    unsigned int split(int n)
    {
    if(n >= (n/2 + n/3 + n/4))
    return n;
    if(n<1000000)
    {
    if(arr[n] == 0)
    arr[n] = split(n/2)+split(n/3)+split(n/4);
    return arr[n];
    }
    return (split(n/2)+split(n/3)+split(n/4));
    }

    int main()
    {
    int n,i;
    arr[0] = 0;
    arr[1] = 1;
    while(scanf("%d", &n)!=EOF)
    {
    printf("%u\n", split(n));
    }
    return 0;
    }
