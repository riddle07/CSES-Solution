#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<long long, long long>> v;
    for(int i = 0; i<n; i++){
        long long x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    long long ans = 1;
    long long last_end = v[0].second;
    for(int i = 0; i<n; i++){
        if(v[i].first<last_end){
            last_end = min(last_end, v[i].second);
        }
        else{
            last_end = v[i].second;
            ans++;
        }
    }
    cout<<ans<<endl;
}