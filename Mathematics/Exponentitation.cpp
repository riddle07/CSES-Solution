#include <bits/stdc++.h>
#define m (long long)(1e9 + 7)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        if (!a && !b)
        {
            cout << 1 << endl;
            continue;
        }
        a %= m;
        long long res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        cout << res << endl;
    }
}