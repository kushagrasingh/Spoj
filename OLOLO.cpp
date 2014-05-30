
#include <cstdio>

using namespace std;

int main ()
{
int t;
int n;
scanf( "%d\n", &n );
int answer;
for( int i=0; i<n; ++i )
{
scanf( "%d\n", &t );
if( i == 0 )
answer = t;
else
answer ^= t;
}
printf( "%d\n", answer );
}
