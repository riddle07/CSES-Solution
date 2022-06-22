#include <bits/stdc++.h>

using namespace std;

vector<char> ans;

void dfs(vector<string> &v, int i, int j, vector<char> temp)
{
    if (i < 0 || i >= v.size() || j < 0 || j >= v[0].length() || v[i][j] == '#')
        return;
    if (v[i][j] == 'B')
    {
        ans = temp;
        return;
    }
    v[i][j] = '#';
    temp.push_back('U');
    dfs(v, i - 1, j, temp);
    temp.pop_back();
    temp.push_back('D');
    dfs(v, i + 1, j, temp);
    temp.pop_back();
    temp.push_back('L');
    dfs(v, i, j - 1, temp);
    temp.pop_back();
    temp.push_back('R');
    dfs(v, i, j + 1, temp);
    temp.pop_back();
}

int main()
{
    int n, m;
    cin >> n >> m;
    cin.get();
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int a, b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                a = i;
                b = j;
                break;
            }
        }
    }
    dfs(v, a, b, {});
    if (ans.size())
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x;
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}