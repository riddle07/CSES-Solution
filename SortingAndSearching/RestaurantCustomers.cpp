#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<long long, int>> v;
    for(int i = 0; i<n; i++){
        long long x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,1));
        v.push_back(make_pair(y,-1));
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    long long crt = 0;
    for(auto x:v){
        crt += x.second;
        ans = max(ans, crt);
    }
    cout<<ans<<endl;
}