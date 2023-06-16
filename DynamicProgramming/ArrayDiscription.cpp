#include <bits/stdc++.h>

using namespace std;

long long mod = (long long)(1e9 + 7);

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));
    if (v[0] == 0)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = 1;
        }
    }
    else
    {
        dp[0][v[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j - 1 >= 1)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                if (j + 1 <= m)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
        }
        else
        {
            if (v[i] - 1 >= 1)
            {
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] - 1]) % mod;
            }
            if (v[i] + 1 <= m)
            {
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] + 1]) % mod;
            }
            dp[i][v[i]] += (dp[i][v[i]] + dp[i - 1][v[i]]) % mod;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n - 1][m]) % mod;
    }
    cout << ans << endl;
}