#include <iostream>

using namespace std;

int main ()
{
string S, T;
while( cin >> S >> T )
{
if( S == "*" && T == "*" )
break;
int c = 0;
int size = S.size();
bool changing = false;
for( int i=0; i<size; ++i )
{
if( S[i] != T[i] && !changing )
{
++c;
changing = true;
}
else if( S[i] == T[i] )
changing = false;
}
cout << c << endl;
}
