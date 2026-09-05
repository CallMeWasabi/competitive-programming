#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

const int sz = 2e5 + 5;
vector<int> par(sz);

int fin(int a) {
    if (par[a] == a) return a;
    return par[a] = fin(par[a]);
}

void uni(int a, int b) {
    par[fin(b)] = fin(a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    iota(par.begin(), par.end(), 0);

    vector<tuple<ll, ll, ll, ll>> edge;
    edge.reserve(sz);

    int n, c;
    cin >> n >> c;
    for (int i=1; i<=n; i++) {
        ll t, u, w, v;

        cin >> t;
        if (t == 1) cin >> u, w = u;
        else cin >> u >> w;
        cin >> v;

        edge.push_back({v, u, w, i});
    }

    sort(edge.begin(), edge.end(), greater<>());

    bool cycle = false;
    ll cost = 0;
    vector<tuple<ll, ll, ll>> ans;
    for (int i=0; i<edge.size(); i++) {
        auto &[v, u, w, j] = edge[i];

        if ((u != w && fin(u) == fin(w) && cycle) || (u == w && cycle)) continue;
        if (u == w || (u != w && fin(u) == fin(w))) cycle = true;
        uni(u, w);

        cost += v;
        ans.push_back({u, w, j});
    }

    cout << cost << '\n';
    for (auto &[u, w, j]: ans) cout << u << ' ' << w << ' ' << j << '\n';

    return 0;
}
