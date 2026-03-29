#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int pat = 0;
vector<vector<bool>> vis(7, vector<bool>(7, false));

void solve(string& s, int i, int j, int step) {
    cout << i << ' ' << j << '\n';

    if (i==0 && j==6 && step==s.length()) {
        pat++;
        return;
    }

    if (i<0||j<0||i>6||j>6||step>=s.length()||vis[i][j]) return;

    vis[i][j]=1;
    if (s[step]=='?') {
        solve(s, i+1, j, step+1);
        solve(s, i-1, j, step+1);
        solve(s, i, j+1, step+1);
        solve(s, i, j-1, step+1);
    }
    else if (s[step]=='R') solve(s, i, j+1, step+1);
    else if (s[step]=='L') solve(s, i, j-1, step+1);
    else if (s[step]=='D') solve(s, i+1, j, step+1);
    else if (s[step]=='U') solve(s, i-1, j, step+1);
    vis[i][j]=0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;

    solve(s, 0, 0, 0);

    cout << pat;

    return 0;
}
