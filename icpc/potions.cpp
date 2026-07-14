#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll h[2001][2], dp[2001][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i: v) cin >> i;

    if (v[0] >= 0) {
        h[0][0] = dp[0][0] = 0;
        h[0][1] = v[0];
        dp[0][1] = 1;
    }

    for (int i=1; i<n; i++) {
        h[i][0] = h[i-1][0];
    }

    return 0;
}
