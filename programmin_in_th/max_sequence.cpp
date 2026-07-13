#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n), dp(n, INT32_MIN);
    for (auto &i: v) cin >> i;
    int mx=v[0], al=0, ar=0, l=0;
    dp[0]=v[0];
    for (int i=1; i<n; i++) {
        if (dp[i-1]+v[i] > v[i]) {
            dp[i]=dp[i-1]+v[i];
            if (dp[i]>mx) mx=dp[i], al=l, ar=i;
        } else {
            dp[i]=v[i];
            l=i;
            if (dp[i]>mx) mx=dp[i], al=l, ar=i;
        }
    }

    if (mx <= 0) cout << "Empty sequence";
    else {
        for (int i=al; i<=ar; i++) cout << v[i] << ' ';
        cout << '\n' << mx;
    }

    return 0;
}
