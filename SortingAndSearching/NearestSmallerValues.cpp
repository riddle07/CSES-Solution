#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    stack<int> s;
    vector<int> ans(n,0);
    for(int i = n-1; i>=0; i--){
        while((!s.empty())&&(v[i]<v[s.top()])){
            ans[s.top()] = i+1;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        ans[s.top()] = 0;
        s.pop();
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}