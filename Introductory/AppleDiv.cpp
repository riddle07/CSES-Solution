#include <bits/stdc++.h>

using namespace std;

long long global = LLONG_MAX;

void helper(vector<long long> &nums, int i, long long ans){
    if(i==nums.size())
    {
        global = min(global,ans);
        return;
    }

    ans = ans+nums[i];

    helper(nums,i+1,ans);

    ans = ans - 2*nums[i];

    helper(nums,i+1,ans);
}

int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    helper(v,0,0);
    cout<<global<<endl;
    return 0;
}