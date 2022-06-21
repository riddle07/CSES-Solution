#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long sum;
    cin>>sum;
    vector<long long> v(n);
    vector<int> ans = {-1,-1,-1};
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    for(int i = 0; i<n; i++){
        long long n_target = sum-v[i];
        map<long long,int> mp;
        for(int j = i+1; j<n; j++){
            if(mp.count(n_target-v[j])){
                ans = {i+1, j+1, mp[n_target-v[j]]+1};
            }
            mp[v[j]] = j;
        }
    }
    if(ans[0]!=-1)
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}