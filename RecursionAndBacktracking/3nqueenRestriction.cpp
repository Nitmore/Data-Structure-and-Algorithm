#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 8;
int queen[N];
int blocked[N][N];

bool check(int row, int col) {
    for (int pr = 0; pr < row; pr++) {
        int pc = queen[pr];
        if (pc == col || abs(pr - row) == abs(pc - col)) return false;
    }
    return true;
}

int rec(int level) {
    if (level == N) return 1;

    int ans = 0;
    for (int ch = 0; ch < N; ch++) {
        if (!blocked[level][ch] &&check(level, ch)) {
            queen[level] = ch;
            ans += rec(level + 1);
            queen[level] = -1;
        }
    }
    return ans;
}

void solve() {
    
    memset(queen, -1, sizeof(queen));
    memset(blocked,0,sizeof(blocked));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char ch;
            cin>>ch;
            if(ch=='*') blocked[i][j]=1;
        }
    }
    

    cout << rec(0) << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
