#include <bits/stdc++.h>

using namespace std;

int dp[(int)(1 << 20) + 1];

long long dfs(vector<long long> &v, int mask, long long cv, long long limit)
{
    if (__builtin_popcount(mask) == 0)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    long long ans = LLONG_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        if (mask & (1 << i))
        {
            if (v[i] + cv <= limit)
            {
                ans = min(ans, dfs(v, (mask ^ (1 << i)), cv + v[i], limit));
            }
            else
            {
                ans = min(ans, 1 + dfs(v, mask ^ (1 << i), v[i], limit));
            }
        }
    }
    return dp[mask] = ans;
}

int main()
{
    int n;
    cin >> n;
    long long x;
    cin >> x;
    memset(dp, -1, sizeof(dp));
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    long long mask = (1 << (n)) - 1;
    cout
        << 1 + dfs(v, mask, 0, x) << endl;
}