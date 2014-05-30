#include<stdio.h>

int max(int a,int b)
{
        return a>b?a:b;
}
int Knapsack(int items,int weight[],int value[],int maxWeight)
{
        int dp[items+1][maxWeight+1];
        /* dp[i][w] represents maximum value that can be attained if the maximum weight is w and
           items are chosen from 1...i */
        /* dp[0][w] = 0 for all w because we have chosen 0 items */
        int iter,w;
        for(iter=0;iter<=maxWeight;iter++)
        {
                dp[0][iter]=0;
        }
        /* dp[i][0] = 0 for all w because maximum weight we can take is 0 */
        for(iter=0;iter<=items;iter++)
        {
                dp[iter][0]=0;
        }
        for(iter=1;iter<=items;iter++)
        {
                for(w=0;w<=maxWeight;w++)
                {
                        dp[iter][w] = dp[iter-1][w]; /* If I do not take this item */
                        if(w-weight[iter] >=0)
                        {
                                /* suppose if I take this item */
                                dp[iter][w] = max(dp[iter][w] , dp[iter-1][w-weight[iter]]+value[iter]);
                        }
                }

        }
        return dp[items][maxWeight];
}

int main()
{
int tests;
scanf("%d",&tests);
while(tests--)
{
    int K,M;
    scanf("%d %d",&K,&M);
        int weights[M+1];
        int values[M+1];
        int i;
        for(i=1;i<=M;i++)
        {
            scanf("%d %d",&weights[i],&values[i]);
        }

        printf("Hey stupid robber, you can get %d.\n",Knapsack(M,weights,values,K));
}
return 0;
}

