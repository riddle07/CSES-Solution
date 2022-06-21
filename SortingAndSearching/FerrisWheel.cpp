#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long x;
    cin>>x;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int i = 0;
    int j = n-1;
    int ans = 0;
    while(i<=j){
        if(i==j){
            ans++;
            break;
        }
        else if(v[i]+v[j]<=x){
            i++;
            j--;
        }
        else j--;
        ans++;
    }
    cout<<ans<<endl;
}