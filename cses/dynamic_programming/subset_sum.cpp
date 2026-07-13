#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    const int k=1e5+5;
    vector<ll> v(n);
    vector<bool> dp(k, 0);

    for (auto &i: v) cin >> i;

    dp[0] = 1;
    for (auto &i: v) for (int j=k-i; j>=0; j--) dp[j+i] = dp[j+i] | dp[j];

    int c=0;
    for (int i=1; i<k; i++) if (dp[i]) c++;

    cout << c << '\n';
    for (int i=1; i<k; i++) if (dp[i]) cout << i << ' ';

    return 0;
}

/*
 * Fn = Fn-1 + Fn-2
 */
