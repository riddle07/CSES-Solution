#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    int i = 0;
    int j = 0;
    unordered_map<long long,int> mp;
    int ans = 0;
    while(j<n){
        while(mp.count(v[j])){
            mp.erase(v[i]);
            i++;
        }
        mp[v[j]]++;
        ans = max(ans, j-i+1);
        j++;
    }
    cout<<ans<<endl;
}