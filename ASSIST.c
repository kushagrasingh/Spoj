#include<stdio.h>


int lucky[3333];
int luckies;

void init_lucky()
{
int islucky[35000];
int i,j;
int c;

for(i=2;i<35000;i++)islucky[i] = 1;
luckies = 0;

for(i=2;luckies<3000;i++)
{
if(islucky[i])
{
lucky[++luckies] = i;
for(j=i,c=0;j<35000;j++)
if(islucky[j])
{
if(c++ == i)
{
islucky[j] = 0;
c = 1;
}
}
}
}
}

int main()
{
init_lucky();
int n;

while(1)
{
scanf("%d",&n);
if(n==0) break;

printf("%d\n",lucky[n]);
}


return 0;
}

