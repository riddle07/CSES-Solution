#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    if(s.length()==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    int i = 0;
    int j = 1;
    int ans = 1;
    while(j<s.length()){
        if(s[j]!=s[j-1]){
            i = j;
        }
        ans = max(ans, j-i+1);
        j++;
    }
    cout<<ans<<endl;
}