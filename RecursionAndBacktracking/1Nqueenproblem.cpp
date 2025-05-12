# include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

#define ffor(i, a, b) for (int i = (a); i < (b); i++)    
#define rfor(i, a, b) for (int i = (a); i >= (b); i--)          
#define foritv(it, v) for (auto it = (v).begin(); it != (v).end(); ++it)

int queen[10];// level
int n;

bool check(int row, int col){
    for(int pr=0; pr<row;pr++){  // pr= purana row;
                                 // pc= purana column;
        int pc=queen[pr];

        if(pc==col || abs(pr-row)==abs(pc-col)){
            return false;
        }
    }
    return true;
}

int rec(int level){
    // given that level we know in which row at what column queens are placed [0.....level-1] in queens
    // explore all possible solution by deciding [level.....n-1]
    // and count them
    // base case
    if(level==n){
        // if want to print the board;
       cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(queen[i]==j) cout<<" Q ";
                else cout<<" * ";
            }
            cout<<endl;
        }
        return 1;
    }
    // recursion include choice,check and move;
    int ans=0;
    for(int ch=0;ch<n;ch++){
        if(check(level, ch)){
            //move
            //place
            queen[level]=ch;
            // call for checking possible way to put queens on level+1;
            ans+=rec(level+1);

            // removing ch to check for other ch;
            queen[level]=-1;
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    memset(queen,-1,sizeof(queen));
    cout<<rec(0);
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