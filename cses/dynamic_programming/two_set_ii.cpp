#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll sum = n*(n+1)/2;
    if (sum%2==1) {
        cout << 0;
        return 0;
    }

    vector<ll> dp(sum+1, 0);

    dp[0]=1;
    for (int i=1; i<n; i++) {
        for (int j=n; j>=i; j--) {
            dp[j] += dp[j-i];
            dp[j] %= (int)1e9 + 7;
        }
    }

    // for (int i=0; i<=n; i++) cout << i << ": " << dp[i] << '\n';
    cout << dp[n];

    return 0;
}
