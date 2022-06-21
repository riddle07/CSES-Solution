#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    long long k;
    cin>>k;
    vector<long long> a(n);
    vector<long long> b(m);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int j = 0; j<m; j++){
        cin>>b[j];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i<n&&j<m){
        if(abs(a[i]-b[j])<=k){
            ans++;
            i++;
            j++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else i++;
    }
    cout<<ans<<endl;
    return 0;
}