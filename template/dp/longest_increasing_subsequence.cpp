#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> n_sqrt(vector<int>& input) {
    vector<int> dp(input.size(), 1);

    for (int i=1; i<input.size(); i++) {
        for (int j=0; j<i; j++) {
            if (input[i] > input[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp;
}

vector<int> n_log_n(vector<int>& input) {
    vector<int> dp;
    for (int i=0; i<input.size(); i++) {
        if (input[i] > dp.back())  dp.push_back(input[i]);
        else {
            int ind = lower_bound(dp.begin(), dp.end(), input[i]) - dp.begin();
            dp[ind] = input[i];
        }
    }

    return dp;
}

int bs(vector<int>& v, int k) {
    int l = 0, r = v.size();
    while (l<r) {
        int m = (l+r)/2;
        if (v[m]>=k) r=m;
        else l=m+1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;

    vector<int> dp; // BIS = best increasing subsequence
    for (int i=0; i<n; i++) {
        int k = v[i];
        if (dp.empty() || dp.back() < k) dp.push_back(k);
        else {
            int pos = bs(dp, k);
            dp[pos] = k;
        }
    }

    cout << dp.size();

    return 0;
}

/* BIS
 * {7}
 * {3}
 * {3, 5}
 * {3, 5}
 * {3, 5, 6}
 * {2, 5, 6}
 * {2, 5, 6, 9}
 * {2, 5, 6, 8}
 */
