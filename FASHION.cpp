#include<math.h>
#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
  while(n > 0)
    {
        int x,i=1,fact=0;
        scanf("%d",&x);;
            while( (x/pow(5,i)) >= 1 )
            {
                int xx = (x/pow(5,i));
                fact = fact + xx;
                i++;
            }
        n--;
        printf("%d\n",fact);

    }
    return 0;
}
