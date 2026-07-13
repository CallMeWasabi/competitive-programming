#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// solved

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> h(n), s(n);
    for (auto &i: h) cin >> i;
    for (auto &i: s) cin >> i;

    vector<ll> dp(x+1, 0);
    for (int i=0; i<n; i++) {
        for (int j=x-h[i]; j>=0; j--) {
            dp[j+h[i]] = max(dp[j+h[i]], dp[j] + s[i]);
        }
    }

    cout << dp[x];

    return 0;
}
