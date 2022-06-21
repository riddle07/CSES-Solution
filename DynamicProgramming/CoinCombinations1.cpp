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
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for(int i = 0; i<=x; i++){
        dp[0][i] = 0;
    }
    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=x; j++){
            if(v[i-1]<=j){
                dp[i][j] = (dp[i][j-v[i-1]]+dp[i-1][j])%mod;
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}