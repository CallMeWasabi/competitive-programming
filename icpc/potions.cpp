#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2002][2002];

ll solve(vector<ll>& v, int i, int c, ll h) {
    if (i == v.size()) return h;
    if (dp[i][c] != -1) return dp[i][c];

    ll pick = -1;
    if (h + v[i] >= 0) pick = solve(v, i+1, c+1, h+v[i]);

    ll not_pick = solve(v, i+1, c, h);
    return dp[i][c] = max(pick, not_pick);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i: v) cin >> i;

    memset(dp, -1, sizeof(dp));
    solve(v, 0, 0, 0);

    ll mx=-1;
    for (int i=0; i<=2000; i++) if (dp[n-1][i] != -1) mx=i+1;

    cout << mx;

    return 0;
}
