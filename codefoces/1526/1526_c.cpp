#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;

const ll INF = 1e9 + 7;
ll dp[2002][2002], v[2002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i];

    memset(dp, -1, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));

    for (int i=1; i<=n; i++) { // consider potion from 1..i
        for (int j=n; j>=1; j--) { // consider drink j
            if (dp[i-1][j-1] + v[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + v[i]);
        }
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) cout << dp[i][j] << ' ';
        cout << '\n';
    }

    // cout << dp[n][n];

    return 0;
}
