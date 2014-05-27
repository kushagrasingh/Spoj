/**  MARBLES SPOJ
*   Let s_i be the number of balls of colour i, where i=1,2,...,k.
*   We know that each s_i is a positive integer and summation(s_i) = n.
*   Hence, we wish to count the number of ways of partitioning n into s_1 + s_2 + ... + s_k (positive integers).
*   This can be done by writing n as 1+1+....+1, n number of ones.
*   Now, each partitioning can be obtained by choosing k-1 "+" signs.
*   Let's look at one example: 10 = 1 + 3 + 3 + 2 + 1.
*   This corresponds to choosing the addition signs:
*   10 = 1 (+) 1+1+1 (+) 1+1+1 (+) 1+1 (+) 1.
*   Hence the number of choices is C(n-1, k-1)
**/

#include <iostream>

using namespace std;

long long cnr(int n, int r)
{
    long long res = 1;
    for (int i = 1; i <= r; ++i) res *= n - i + 1, res /= i;
    return res;
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, k;
        cin >> n >> k;
        // (n-1)C(k-1)
        cout << cnr(n - 1,min(n-k,k-1)) << endl;
    }
}
