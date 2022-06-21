#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1));
    dp[0][0] = 0;
    for(int i = 1; i<=a.length(); i++){
        dp[i][0] = dp[i-1][0]+1;
    }
    for(int j = 1; j<=b.length(); j++){
        dp[0][j] = dp[0][j-1]+1;
    }
    for(int i = 1; i<=a.length(); i++){
        for(int j = 1; j<=b.length(); j++){
            if(a[i-1]==b[j-1])
            dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
    cout<<dp[a.length()][b.length()]<<endl;
    return 0;
}