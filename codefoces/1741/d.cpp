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
#include <numeric>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;

ll cnt = 0;
bool possible = 1;

void solve(vector<ll>& v, ll l, ll r) {
    if (!possible) return;
    if (r-l == 1) return;
    ll m = (l+r)/2;
    solve(v, l, m);
    solve(v, m, r);

    vector<ll> left(v.begin()+l, v.begin()+m), right(v.begin()+m, v.begin()+r);

    // test all left is greater that right
    bool test_left = 1;
    for (auto &i: left) {
        if (i < right.back()) {
            test_left = 0;
            break;
        }
    }

    // test all right is greater than left
    bool test_right = 1;
    for (auto &i: right) {
        if (i < left.back()) {
            test_right = 0;
            break;
        }
    }

    if (test_left && !test_right) {
        cnt++;
        ll i = 0, j = 0, k = l;
        while (j < right.size()) v[k++] = right[j++];
        while (i < left.size()) v[k++] = left[i++];
    } else if (!test_left && test_right) {
        ll i = 0, j = 0, k = l;
        while (i < left.size()) v[k++] = left[i++];
        while (j < right.size()) v[k++] = right[j++];
    } else {
        possible = 0;
        return;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> v(n);
        for (auto &i: v) cin >> i;

        cnt = 0;
        possible = 1;
        solve(v, 0, n);

        if (possible) cout << cnt << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
