#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char in[100][151];

char words[150][151];

char abbr[151];

long long ans[151][151];

char str[151];

int main()
{
    int i,j,k,n,found,m,no,l;
    scanf("%d",&n);
    while(n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",in[i]);
        }
        scanf("\n%[^\r\n]s",str);
        while(strcmp(str,"LAST CASE")!=0)
        {
            for(i=0;str[i]!=' ';i++)
            {
                abbr[i] = str[i];
            }
            abbr[i]='\0';
            m = i;
            i++;
            j=0;
            k=0;
            for(;str[i]!='\0';i++)
            {
                if(str[i]!=' ')
                    words[j][k++] = str[i];
                else
                {
                    words[j][k] = '\0';
                    found = 0;
                    for(l=0;l<n;l++)
                    {
                        if(strcmp(words[j],in[l])==0)
                        {
                            found=1;
                            break;
                        }
                    }
                    if(!found)
                        j++;
                    k=0;
                }
            }
            words[j][k] = '\0';
            found = 0;
            for(l=0;l<n;l++)
            {
                if(strcmp(words[j],in[l])==0)
                {
                    found=1;
                    break;
                }
            }
            if(!found)
                j++;
            no = j;
            for(i=1;i<=m;i++)
                ans[0][i] = 0;
            ans[0][0] = 1;
            for(i=1;i<=no;i++)
            {
                for(j=1;j<=m;j++)
                    ans[i][j] = 0;
                ans[i][0]=0;
                for(j=0;words[i-1][j]!='\0';j++)
                {
                    for(k=m-1;k>=0;k--)
                    {
                        if(words[i-1][j]==abbr[k]+32)
                        {
                            ans[i][k+1]+=ans[i][k] + ans[i-1][k];
                        }
                    }
                }
            }
            if(ans[no][m]>0)
                printf("%s can be formed in %lld ways\n",abbr,ans[no][m]);
            else
                printf("%s is not a valid abbreviation\n",abbr);
            scanf("\n%[^\r\n]s",str);
        }
        scanf("%d",&n);
    }
    return 0;
}

