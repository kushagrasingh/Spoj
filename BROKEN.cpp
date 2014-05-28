#include<iostream>
#include<stdio.h>

using namespace std;

char str[1000001];

int main()
{
    int k,i,j,max,chars[256],curr,temp,count;
    scanf("%d\n",&k);
    while(k!=0)
    {
        gets(str);
        for(i=0;i<256;i++)
            chars[i]=0;
        i=0;
        j=0;
        count=0;
        max=0;
        for(j=0;str[j]!='\0';j++)
        {
            temp = (int)str[j];
            chars[temp]++;
            if(chars[temp]==1)
            {
                count++;
                while(count>k)
                {
                    temp = (int)str[i];
                    chars[temp]--;
                    i++;
                    if(chars[temp]==0)
                    {
                        count--;
                    }
                }
            }
            curr = j-i+1;
            if(curr>max)
                max=curr;
        }
        printf("%d\n",max);
        scanf("%d\n",&k);
    }
    return 0;
}

