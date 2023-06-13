#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<unsigned long long>> distance(n, vector<unsigned long long>(n, ULLONG_MAX));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        unsigned long long z;
        cin >> x >> y >> z;
        x--;
        y--;
        distance[x][y] = min(distance[x][y], z);
        distance[y][x] = min(distance[x][y], z);
    }
    for (int i = 0; i < n; i++)
    {
        distance[i][i] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[i][k] < ULLONG_MAX && distance[k][j] < ULLONG_MAX)
                {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (distance[a][b] == ULLONG_MAX)
            cout << "-1" << endl;
        else
            cout << distance[a][b] << endl;
    }
    return 0;
}