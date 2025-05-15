# include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

#define ffor(i, a, b) for (int i = (a); i < (b); i++)    
#define rfor(i, a, b) for (int i = (a); i >= (b); i--)          
#define foritv(it, v) for (auto it = (v).begin(); it != (v).end(); ++it)

int n;
int cnt;
vector<int> cur_permutation;
map<int,int> mp;
vector<vector<int>> all_permutation;
bool found=false;
int gin=0;

void rec(int level){
    if(found) return;
    if(level== n) {
        if(gin==cnt-1){
            for(int i=0;i<n;i++){
                cout<<cur_permutation[i]<<" ";
            }
            found=true;
        }
        gin++;
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

// factorial method to solve Kth easy version of making permuation if n>10.
void solve2() {
    int n, k;
    cin >> n >> k;
    k--; 

    vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);

    vector<int> fact(n);
    fact[0] = 1;
    for (int i = 1; i < n; ++i)
        fact[i] = fact[i - 1] * i;

    vector<int> result;

    for (int i = n; i >= 1; --i) {
        int idx = k / fact[i - 1];
        k %= fact[i - 1];
        result.push_back(nums[idx]);
        nums.erase(nums.begin() + idx);
    }

    for (int num : result) cout << num << " ";
    cout << "\n";
}

// factorial method to solve Kth easy version of making permuation if N<10.
void solve(){
    
    cin>>n>>cnt;
    vector<int> arr;
    for(int i=0;i<n;i++){
        arr.push_back(i+1);
        mp[arr[i]]++;
    }
    rec(0);
    
//     for (auto v : all_permutation) {
//         for (auto x : v) {
//             cout << x << " ";
//         }
//         cout << "\n";
// }

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