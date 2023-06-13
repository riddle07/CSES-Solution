#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x;
    cin >> x;
    int n;
    cin >> n;
    set<long long> s;
    multiset<long long> ms;
    s.insert(0);
    s.insert(x);
    ms.insert(x - 0);
    for (int i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        auto it = s.lower_bound(val);
        long long high_val = *it--;
        long long low_val = *it;
        s.insert(val);
        ms.erase(ms.find(high_val - low_val));
        ms.insert(val - low_val);
        ms.insert(high_val - val);
        it = --ms.end();
        long long ans = *it;
        cout << ans << " ";
    }
    cout << endl;
}