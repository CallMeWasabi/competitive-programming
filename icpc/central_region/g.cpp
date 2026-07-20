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
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<int>;

vector<pii> tree[200005];
vector<bool> used(200005, false);

ll solve(int v, int c) {
    if (tree[v].empty()) return 0;

    used[v] = 1;
    ll s = 0;
    set<int> dist_color;
    for (auto &[nxt, nxt_c]: tree[v]) {
        if (used[nxt]) continue;

        s += solve(nxt, nxt_c);
        if (nxt_c != c) dist_color.insert(nxt_c);
    }
    used[v] = 0;

    return s + dist_color.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});
    }

    ll s = 0;
    set<int> dist_color;

    used[1] = 1;
    for (auto &[v, c]: tree[1]) {
        s += solve(v, c);
        dist_color.insert(c);
    }
    used[1] = 0;

    cout << s + dist_color.size();

    return 0;
}
