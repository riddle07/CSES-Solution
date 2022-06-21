#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    long long crt_ans = v[0];
    long long max_ans = v[0];
    for(int i = 1; i<n; i++){
        crt_ans = max(v[i], crt_ans+v[i]);
        max_ans = max(max_ans, crt_ans);
    }
    cout<<max_ans<<endl;
}