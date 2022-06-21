#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++){
        mp[v[i]] = i+1;
    }
    int crt_ans = 0;
    for(int i = 2; i<=n; i++){
        if(mp[i-1]>mp[i])
        crt_ans++;
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        
    }
}