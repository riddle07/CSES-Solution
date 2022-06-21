#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    long long crt_sum = 0;
    for(int i = 0; i<n; i++){
        if(crt_sum+1<v[i])
        break;
        crt_sum += v[i];
    }
    cout<<crt_sum+1<<endl;
    return 0;
}