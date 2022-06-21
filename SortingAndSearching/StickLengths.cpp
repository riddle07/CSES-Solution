#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    long long median = v[n/2];
    long long ans = 0;
    for(auto x:v){
        ans += abs(median-x);
    }
    cout<<ans<<endl;
}