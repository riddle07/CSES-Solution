#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 1; i<=x; i++){
        for(int j = 0; j<n; j++){
            if(v[j]<=i)
            dp[i] = (dp[i]+dp[i-v[j]])%mod;
        }
    }
    cout<<dp[x]<<endl;
}