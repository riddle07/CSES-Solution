#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    long long ans = 0;
    long long start = (long long)5;
    while(n/start){
        ans += (n/start);
        start = start*5;
    }
    cout<<ans<<endl;
    return 0;
}