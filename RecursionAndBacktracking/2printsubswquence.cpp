# include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

#define ffor(i, a, b) for (int i = (a); i < (b); i++)    
#define rfor(i, a, b) for (int i = (a); i >= (b); i--)          
#define foritv(it, v) for (auto it = (v).begin(); it != (v).end(); ++it)

int n;
vector <int> sol;
vector<int> arr;

void printsubsequences(int level){
    if(level==n){
        if(sol.size()!=0){
            for(int i=0;i<sol.size();i++){
            cout<<sol[i]<<" ";
            }
            cout<<endl;
        }
        
        else cout<<"{}"<<endl;
        
        return;
    }
    sol.push_back(arr[level]);
    printsubsequences(level+1);
    sol.pop_back();
    printsubsequences(level+1);
    
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        arr.push_back(i+1);
    }
    printsubsequences(0);
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