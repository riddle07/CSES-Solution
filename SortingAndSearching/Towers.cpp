#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    vector<int> dp;
    dp.push_back(v[0]);
    for(int i = 1; i<n; i++){
        if(v[i]>=dp[dp.size()-1]){
            dp.push_back(v[i]);
        }
        else {
            int ind = upper_bound(dp.begin(),dp.end(), v[i])-dp.begin();
            dp[ind] = v[i];
        }
    }
    cout<<dp.size()<<endl;
}