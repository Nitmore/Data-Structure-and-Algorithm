#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> queens;

int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={-1,-2,-2,-1,1,2,2,1};

bool isvalid(int x, int y){
    if(x>=0 && y>=0 && x<n && y<n){
        return true;
    }
    return false;
}

bool issafe(int rows, int col){
    for(int r=0;r<rows;r++){
        int c=queens[r];
        if(col==c || abs(rows-r)==abs(col-c)) return false;
    

    for(int i=0;i<8;i++){
        int x= r +dx[i];
        int y=c+ dy[i];
        if(isvalid(x,y)){
            if(x==rows && y==col) return false;
        }
    }
}
return true;
}

int lccm(int level){
    if(level==n) return 1;

    int ans=0;

    for(int ch=0;ch<n;ch++){
        if(issafe(level,ch)){
            queens[level]=ch;
            ans+=lccm(level+1);
            queens[level]=-1;
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    queens.assign(n,-1);
    
    cout<<lccm(0)<<endl;;
}

signed main(){

    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}