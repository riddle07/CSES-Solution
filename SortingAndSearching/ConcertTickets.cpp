#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    multiset<long long> ms;
    for(int i = 0 ; i<n; i++){
        long long x;
        cin>>x;
        ms.insert(x);
    }
    for(int j = 0; j<m; j++){
        long long this_price;
        cin>>this_price;
        auto up = ms.upper_bound(this_price);
        if(up == ms.begin()){
            cout<<"-1"<<endl;
        }
        else{
            cout<<*(--up)<<endl;
            ms.erase(up);
        }
    }
    return 0;
}