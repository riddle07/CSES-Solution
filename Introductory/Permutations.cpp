#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"1"<<endl;
    }
    else if(n<4){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        deque<int> dq;
        dq.push_back(2);
        dq.push_back(4);
        dq.push_back(1);
        dq.push_back(3);
        if(n==4){
            while(!dq.empty()){
                cout<<dq.front()<<" ";
                dq.pop_front();
            }
        }
        else{
            for(int i = 5; i<=n; i++){
                if(i%2)
                dq.push_front(i);
                else
                dq.push_back(i);
            }
            while(!dq.empty()){
                cout<<dq.front()<<" ";
                dq.pop_front();
            }
        }
    }
}