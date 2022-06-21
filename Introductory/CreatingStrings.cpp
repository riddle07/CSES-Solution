#include <bits/stdc++.h>

using namespace std;
 
long long factorial(long long n){
    long long f = 1;
    for(long long i = 2; i<=n; i++){
        f = f*i;
    }
    return f;
}

int main(){
    string a;
    cin>>a;
    long long n;
    n = (long long)a.length();
    long long loop_end = factorial(n);
    set<string> s;
    while(loop_end){
        s.insert(a);
        next_permutation(a.begin(), a.end());
        loop_end--;
    }
    cout<<s.size()<<endl;
    for(auto x:s){
        cout<<x<<endl;
    }
    return 0;
}