#include <bits/stdc++.h>

using namespace std;

int number(vector<int> v){
    for(int i = 1; i<v.size(); i++){
        if(v[i]!=i)
        return i;
    }
    return v.size();
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 1; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    cout<<number(v)<<endl;
    return 0;
}