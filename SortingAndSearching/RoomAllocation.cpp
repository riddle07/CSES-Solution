#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<long long, long long>> v;
    for(int i = 0; i<n; i++){
        long long x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,1));
        v.push_back(make_pair(y,-1));
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    long long ans = 0;
    for(auto x:v){
        sum += x.second;
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
}