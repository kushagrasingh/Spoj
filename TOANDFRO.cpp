SPOJ submission 6738013 (C) plaintext list. Status: AC, problem TOANDFRO, contest SPOJ. By mindfuck (mindfuck), 2012-03-27 23:30:53.
#include<stdio.h>
#include<string.h>
int main()
{
    while(1)
 {
      int n;
    scanf("%d",&n);
   if(n == 0)
   {
       //break;
       return 0;
   }

   char str[200];
    scanf("%s",&str);
    int i,j,a=0;
int len = strlen(str);
char str2[(len/n)][n];

   for(i=0;i<(len/n);i++)
   {
       if ((i%2) == 0 )
       {
            for(j=0;j<n;j++)
            {
                str2[i][j] = str[a];
                a++;
            }
        }
        else if((i%2) == 1)
        {
            for(j=n-1; j>=0;j--)
            {
                str2[i][j] = str[a];
                a++;
            }
        }
    }
/*
   for(i=0;i<(len/n);i++)
   {
       for(j=0;j<n;j++)
       {
printf("%c",str2[i][j]);
       }
       printf("\n");
   }
*/
for(j=0;j<n;j++)
{
    for(i=0;i<(len/n);i++)
    {
        printf("%c",str2[i][j]);
    }
}
printf("\n");
 }
    return 0;
}

