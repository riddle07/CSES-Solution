#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long z;
    cin>>z;
    map<long long, int> mp;
    unsigned long long ans = 0;
    long long crt_sum = 0;
    mp[0]++;
    for(int i = 0; i<n; i++){
        long long x;
        cin>>x;
        crt_sum += x;
        if(mp.count(crt_sum-z)){
            ans += (unsigned long long)(mp[crt_sum-z]);
        }
        mp[crt_sum]++;
    }
    cout<<ans<<endl;
    return 0;
}