/*
Problem - ONP Spoj
Reverse Polish Notation :
Keep pushing the operators on top of the stack and variables in the result array.
As we see a ) closing bracket, pop the operator from stack and add it to result array.
*/
#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        char arr[500];

        stack<char> op;
        vector<char> exp;
        vector<char>::iterator it;

        memset(arr, 0, sizeof(arr));
        gets(arr);
        int i, len = strlen(arr);

        for( i=0; i<len; i++) {
            if( isalnum(arr[i])){
                exp.push_back(arr[i]);
            } else if( arr[i] == ')'){
                exp.push_back(op.top());
                op.pop();
            } else if( arr[i] == '('){
            } else{
                op.push(arr[i]);
            }
        }

        for( it = exp.begin(); it != exp.end(); it++)
            cout<< *it << endl;;
    }
    return 0;
}
