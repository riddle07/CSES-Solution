#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sum = (n*(n+1))/2;
    if(sum%2){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        long long last_big = n;
        unordered_map<long long, int> mp;
        long long temp = sum/2;
        while(temp){
            if(temp<last_big){
                mp[temp]++;
                temp = 0;
            }
            else{
                temp = temp-last_big;
                mp[last_big]++;
                last_big--;
            }
        }
        cout<<mp.size()<<endl;
        for(auto x:mp){
            cout<<x.first<<" ";
        }
        cout<<endl;
        cout<<n-mp.size()<<endl;
        for(int i = 1; i<=n; i++){
            if(!mp.count(i))
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}