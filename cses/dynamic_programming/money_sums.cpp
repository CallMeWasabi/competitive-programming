#include <ios>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;

    const int k = 100 * 1000 + 1;
    vector<int> dp(k, false);
    dp[0] = true;
    for (int i=0; i<n; i++) {
        for (int  j=k-v[i]; j>=0; j--) {
            if (dp[j]) dp[j+v[i]] = true;
        }
    }

    vector<int> ans;
    ans.reserve(dp.size());

    for (int i=1; i<k; i++) {
        if (dp[i]) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (auto &i: ans) cout << i << ' ';

    return 0;
}
