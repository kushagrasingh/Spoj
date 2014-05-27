#include <iostream>
#include <stdio.h>

using namespace std;

char str[1000001];
int heap[1000000] = {0};

void update(int pos, int n) {
    int left, right, temp, mpos;
    if(pos >= n)
        return;
    left = pos<<1;
    right=left+1;
    if(left>=n)
        return;
    mpos = left;
    if( right < n && heap[right] < heap[left])
        mpos = right;
    if( heap[pos] > heap[mpos] ) {
        temp = heap[pos];
        heap[pos] = heap[mpos];
        heap[mpos] = temp;
        update(mpos,n);
    }
}

int main() {
    int n,i,j,min1,min2,pos;
    scanf("%d",&n);
    scanf("%s",&str);
    for(i=0;str[i]!='\0';i++) {
        if(str[i]=='1') {
            heap[0]++;
            update(0,n);
        } else {
            if (n==2 || heap[1] < heap[2] ) {
                pos = 1;
            } else {
                pos = 2;
                heap[pos]++;
            }
        }
    }
    min1 = heap[0];
    if ( n==2 || heap[1] < heap[2] ) {
        min2 = heap[1];
    } else {
        min2 = heap[2];
    }

    printf("%d %d\n",min1,min2);
    return 0;
}
