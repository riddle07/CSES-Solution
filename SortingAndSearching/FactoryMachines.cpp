#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    unsigned long long t;
    cin>>t;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    unsigned long long low = 0;
    unsigned long long high = ULLONG_MAX;
    unsigned long long ans = ULLONG_MAX;
    while(low<=high){
        unsigned long long mid = low + (high-low)/2;
        unsigned long long crt_count = 0;
        for(auto x:v){
            crt_count += (mid/x);
        }
        if(crt_count>=t){
            ans = min(mid, ans);
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<ans<<endl;
    return 0;
}