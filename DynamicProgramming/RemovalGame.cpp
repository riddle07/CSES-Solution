#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n));

    for(int i = n-1; i>=0; i--){
        for(int j = i; j<n; j++){
            if(i==j){
                dp[i][j] = v[i];
            }
            else{
                dp[i][j] = max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
            }
        }
    }
    long long sum = accumulate(v.begin(), v.end(), (long long)0);
    cout<<(sum+dp[0][n-1])/2<<endl;
    return 0;
}