#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    cin.get();
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    if(v[0][0]=='*'||v[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<long long>> dp(n,vector<long long> (n,0LL));
    dp[0][0] = 1;
    for(int i = 1; i<n; i++){
        if(v[i][0]=='*')dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
        if(v[0][i]=='*')dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            if(v[i][j]=='*')
            dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}