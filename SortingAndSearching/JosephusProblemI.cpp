#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ans;
    for(int i = 2; i<=(n/2)*2; i = i+2){
        ans.push_back(i);
    }
    int k = 0;
    for(int i = 2^; i<=100000; i++){
        for(int j = 1+k; j<=n; j = j+i){
            ans.push_back(j);
        }
        if(ans.size()==n)
        break;
        if(!k)
        k++;
        k =k *2;
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}