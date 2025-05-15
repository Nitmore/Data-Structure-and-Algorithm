#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
vector<int> cur_permutation;

void recandsolve(vector<int> & arr){
    int t=arr.size();
    k--;
    int fact=1;
    for(int i=1;i<t;i++){
        fact*=i;
    }

    while(1){
        cur_permutation.push_back(arr[k/fact]);
        arr.erase(arr.begin()+ k/fact);
        if(arr.size()==0) break;
        k%=fact;
        fact/=arr.size();
    }

    for(auto v: cur_permutation){
        cout<<v<<" ";
    }


}

void solve() {
    cin>>n>>k;
    vector<int> arr;
    if(n<=13){
        for(int i=0;i<n;i++){
            arr.push_back(i+1);
        }
    }
    else{
        for(int i=1;i<n-12;i++){
            cout<<i<<" ";
        }
        for(int i=n-12;i<=n;i++){
            arr.push_back(i);
        }
    }
    recandsolve(arr);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
