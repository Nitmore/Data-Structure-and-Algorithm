//Time complexity is (N^2)P(K)
// But this can be optimised to (N^2)C(k); and that code is in 11.1 k_knight.cpp

#include <bits/stdc++.h>
using namespace std;

int n,k;
int ans;
vector<vector<int>> chess;

int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};

bool check( int i , int j){
    if(chess[i][j]==1) return false;
    for(int t=0;t<8;t++){
        int x= i + dx[t];
        int y= j + dy[t];

        if(x<n && y<n && x>0 && y>0 && chess[x][y]==1) return false;
    }
    return true;
}

void rec(int level){ // here level is number of knights;
    if(level==k){
        ans++;
        return;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check(i,j)){
                chess[i][j]=1;
                rec(level+1);
                chess[i][j]=0;
            }
        }
    }


}

signed main(){
    cin>>n>>k;
    chess.resize(n, vector<int>(n, 0));
    rec(0);
    for(int i=1;i<=k;i++){
        ans/=i;
    }
    cout<<ans<<endl;
    return 0;
}