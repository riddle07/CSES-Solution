#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> dp(n+1, LLONG_MAX);
    dp[0] = 0;
    for(int i = 0; i<=n; i++){
        for(auto x:to_string(i)){
            dp[i] = min(dp[i], dp[i-x+48]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}