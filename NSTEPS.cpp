#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x<y)
        {
            printf("No Number\n");
        }
        else if ( ((x%2)==0 ) && ((y+2)==x ))
        {
            printf("%d\n",( (2*x)- 2));
        }
        else if((x%2)==0 && (y)== x)
        {
            printf("%d\n",(2*x));
        }
        else if ( ((x%2)!=0 ) && ((y)==x ))
        {
            printf("%d\n",( (2*x)- 1));
        }
        else if( (x%2)!=0 && ((y+2)== x))
        {
            printf("%d\n",((2*x)-3));
        }
        else
        {
            printf("No Number\n");
        }
        t--;
    }
    return 0;
}

