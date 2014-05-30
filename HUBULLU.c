#include<stdio.h>
int main()
{
    int i,j,k;
    scanf("%d\n",&i);
    while(i--){
    scanf("%d %d",&j,&k);
        if(k==1)
            printf("Pagfloyd wins.\n");
        if(k==0)
            printf("Airborne wins.\n");
    }
    return 0;
}
