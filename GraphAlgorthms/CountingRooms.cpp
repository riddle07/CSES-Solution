#include <bits/stdc++.h>

using namespace std;

void dfs(vector<string> &v, int i, int j)
{
    if (i >= 0 && i < v.size() && j >= 0 && j < v[0].length() && v[i][j] == '.')
    {
        v[i][j] = '#';
        dfs(v, i + 1, j);
        dfs(v, i - 1, j);
        dfs(v, i, j + 1);
        dfs(v, i, j - 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    cin.get();
    vector<string> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.')
            {
                ans++;
                dfs(v, i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}