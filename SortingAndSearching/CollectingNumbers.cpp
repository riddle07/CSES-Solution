#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    unordered_map<long long,int> mp;
    for(int i = 0; i<n; i++){
        mp[v[i]] = i;
    }
    int ans = 1;
    for(int i = 2; i<=n; i++){
        if(mp[i]<mp[i-1])
        ans++;
    }
    cout<<ans<<endl;
}