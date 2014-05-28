#include<stdio.h>
#include<stdlib.h>

int power(int l) {
 int i;
int k=1;
 for(i=0;i<l;i++){
   k = 10*k;
 }
return k;
}

int reverse(int num) {
  int temp;
 temp = num;
int len = 0;
  while(num >0) {
   num=num/10;
    len++;
   }
 int arr[len];
// printf("%d %d\n",len,temp);
 int i=0;
 int rev=0;
 int k =power(len-1);
 for(i=0;i<len;i++) {
    arr[i]=temp%10;
   // printf("%d\n",arr[i]);
    temp = temp/10;
    rev = rev + ((arr[i])*(k));
    k = k/10;

    }
//printf("%d\n",rev);

return rev;
}

int addrev() {
 int num1,num2;
scanf("%d %d",&num1,&num2);
 int rev1 = reverse(num1);
 int rev2 = reverse(num2);
 int sum = rev1 + rev2;
sum = reverse(sum);
printf("%d\n",sum);
return 0;
}

//main
int main() {
 int tests;
 scanf("%d",&tests);
  while(tests != 0) {
   addrev();
   tests--;
  }
return 0;
}
