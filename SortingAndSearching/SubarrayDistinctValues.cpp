#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    int i = 0;
    int j = 0;
    map<long long, int> mp;
    unsigned long long ans = 0;
    while(j<n){
        mp[v[j]]++;
        while(mp.size()>k){
            mp[v[i]]--;
            if(!mp[v[i]])
            mp.erase(v[i]);
            i++;
        }
        ans += (unsigned long long)(j-i+1);
        j++;
    }
    cout<<ans<<endl;
    return 0;
}