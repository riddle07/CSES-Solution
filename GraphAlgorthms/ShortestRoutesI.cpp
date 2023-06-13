#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        graph[x].push_back(make_pair(y, z));
    }
    vector<int> distance(n, INT_MAX);
    distance[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty())
    {
        int crt_node = pq.top().second;
        long long crt_d = pq.top().first;
        pq.pop();
        for (auto x : graph[crt_node])
        {
            if (distance[x.first] > crt_d + x.second)
            {
                distance[x.first] = crt_d + x.second;
                pq.push(make_pair(distance[x.first], x.first));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
}