#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char, int> mp;
    for(auto x:s){mp[x]++;};
    int single_count = 0;
    char cen;
    deque<char> dq;
    bool ok = true;
    for(auto x:mp){
        if(x.second%2){
            if(single_count)
            {
                ok = false;
                break;
            }
            else{
                single_count = 1;
                cen = x.first;
            }
        }
    }
    if(ok){
        if(single_count)
        dq.push_back(cen);
        for(auto x:mp){
            for(int j = 0; j<(x.second/2)*2; j++){
                if(j%2)
                dq.push_back(x.first);
                else
                dq.push_front(x.first);
            }
        }
        while(!dq.empty()){
            cout<<dq.front();
            dq.pop_front();
        }
        cout<<endl;
    }
    else cout<<"NO SOLUTION"<<endl;
    return 0;
}