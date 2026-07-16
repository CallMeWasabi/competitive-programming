#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <utility>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdint>
#include <cmath>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;

const ll INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;

    map<int, tuple<int, int, int>> dp; // size, prev_val, idx;
    for (int i=0; i<n; i++) if (get<0>(dp[v[i] - 1]) + 1 > get<0>(dp[v[i]])) dp[v[i]] = {get<0>(dp[v[i]-1]) + 1, v[i]-1, i};

    ll mx = 0, k = 0;
    for (auto &[f, s]: dp) if (get<0>(s) > mx ) mx = get<0>(s), k = f;

    vector<int> ans;
    ans.reserve(mx);
    for (int i=0, p=k; i<mx; i++) {
        auto &[a, b, c] = dp[p];
        ans.push_back(c);
        p = b;
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &i: ans) cout << i + 1 << ' ';


    return 0;
}
