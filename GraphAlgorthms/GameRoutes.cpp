#include <bits/stdc++.h>
#define mod (long long)(1e9 + 7)
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> dp(n, 0);
    vector<vector<int>> graph(n);
    vector<int> id(n, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        id[y]++;
    }
    queue<int> q;
    for (int i = 1; i < n; i++)
    {
        if (id[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int crt = q.front();
        q.pop();
        for (auto x : graph[crt])
        {
            id[x]--;
            if (!id[x] && (x != 0))
                q.push(x);
        }
    }
    q.push(0);
    dp[0] = 1;
    while (!q.empty())
    {
        int crt = q.front();
        q.pop();
        for (auto x : graph[crt])
        {
            dp[x] = (dp[x] + dp[crt]) % mod;
            id[x]--;
            if (!id[x])
                q.push(x);
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}