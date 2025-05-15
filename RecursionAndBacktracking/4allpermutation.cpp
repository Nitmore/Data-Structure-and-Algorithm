# include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

#define ffor(i, a, b) for (int i = (a); i < (b); i++)    
#define rfor(i, a, b) for (int i = (a); i >= (b); i--)          
#define foritv(it, v) for (auto it = (v).begin(); it != (v).end(); ++it)

int n;
vector<int> cur_permutation;
map<int,int> mp;
vector<vector<int>> all_permutation;

void rec(int level){
    if(level==n) {
        all_permutation.push_back(cur_permutation);
        return;
    }
    
    
    for(auto v:mp){
        if(v.second!=0){
            cur_permutation.push_back(v.first);
            mp[v.first]--;
            rec(level+1);
            cur_permutation.pop_back();
            mp[v.first]++;
        }
    }
}

void solve(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    rec(0);
    
    for (auto v : all_permutation) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << "\n";
}

}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t=1;
    //cin>>t;

    for(int i=0;i<t;i++){
    solve();
    }

return 0;
}