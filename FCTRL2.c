#include<stdio.h>
#define MAX 165
void factorialof(int);
void multiply(int);
int length = 0;
int fact[MAX];

int main(){
    int t;
    scanf("%d",&t);
    while(t>0)
    {
    int num;
    int i;

  //  printf("Enter any integer number : ");
    scanf("%d",&num);

    fact[0]=1;
length = 0;
    factorialof(num);

    //printf("Factorial is : ");
    for(i=length;i>=0;i--){
         printf("%d",fact[i]);
    }

    printf("\n");
    t--;
    }
    return 0;
}
void factorialof(int num){
    int i;
    for(i=2;i<=num;i++){
         multiply(i);
    }
}
void multiply(int num)
{
    long i=0,r=0;
    int arr[MAX];
    for(i=0;i<=length;i++)
    {
        arr[i]=fact[i];
    }

    for(i=0;i<=length;i++)
    {
         fact[i] = (arr[i]*num + r)%10;
         r = (arr[i]*num + r)/10;
    }
    if(r!=0)
    {
         while(r!=0)
         {
             fact[i]=r%10;
             r= r/10;
             i++;
         }
    }
    length = i-1;
}
