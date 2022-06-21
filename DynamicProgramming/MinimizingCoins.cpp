#include <bits/stdc++.h>

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
    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i<=x; i++){
        dp[0][i] = 1000001;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=x; j++){
            if(v[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-v[i-1]], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[n][x]!=(1000001))
    cout<<dp[n][x]<<endl;
    else cout<<"-1"<<endl;
}