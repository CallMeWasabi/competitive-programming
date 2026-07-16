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

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &i: v) cin >> i;
    sort(v.begin(), v.end());

    if (k == 0) {
        if (v[0] > 1) cout << 1 << '\n';
        else cout << -1 << '\n';
        return 0;
    }

    auto it = upper_bound(v.begin(), v.end(), v[k-1]);
    int idx = it - v.begin();
    const int mx = 1e9;

    if (idx == k) cout << v[idx-1] << '\n';
    else cout << -1 << '\n';

    return 0;
}
