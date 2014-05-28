#include<stdio.h>
#include<string.h>
char s1[6101];
int f[6101][6101];
int min(int a,int b)
{
    if(a<b)
        return a;
        else
            return b;
}
int main()
{
   int T;
   int i,j;
  scanf("%d",&T);
   while(T--) {
      scanf("%s",&s1);
      int len = strlen(s1);
      for( i=len-1;i>=0;i--)
         for(j=i+1;j<len;j++)
         {
            if(s1[i]==s1[j])
               f[i][j]=f[i+1][j-1];
            else
               f[i][j]=min(f[i+1][j],f[i][j-1])+1;
         }
      printf("%d\n",f[0][len-1]);
   }
   return 0;
}

