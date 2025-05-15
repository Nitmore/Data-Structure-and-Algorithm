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

void rec(int level, int last_row, int last_col){ // here level is number of knights;
    if(level==k){
        ans++;
        return;
    }
    
    for(int i=last_row;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==last_row && j<=last_col) continue;
            if(check(i,j) ){
                chess[i][j]=1;
                rec(level+1,i,j);
                chess[i][j]=0;
            }
        }
    }


}

signed main(){
    cin>>n>>k;
    chess.resize(n, vector<int>(n, 0));
    rec(0,0,-1);
    cout<<ans;
    return 0;
}