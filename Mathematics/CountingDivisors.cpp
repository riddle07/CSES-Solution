#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int ans = 0;
        for(int i = 1; i<=sqrt(x); i++){
            if(x%i){

            }
            else{
                if(x/i==i)
                ans++;
                else ans += 2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}