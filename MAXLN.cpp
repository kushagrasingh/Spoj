/**
Thale's Theorum says : AB^2 + AC^2 = (2r)^2.
a^2 + b^2 = 4r^2.
s = a^2 + b = 4r^2 + b - b^2.
For max(s) : maximise (b-b^2) when b=1/2. which makes: s = 4r^2 + 1/4.
*/

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,i=0;
    cin>>t;
    while(i<t)
    {
            long long r;
            double s;
            cin>>r;
            s=double(4*r*r)+.25;
            printf("Case %d: %.2lf\n",++i,s);
    }
    return 0;
}
