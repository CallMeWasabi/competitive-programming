#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(string s) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        size_t cu = 0;
        for (auto &c: s)  cu += (size_t)c;
        return splitmix64(cu + FIXED_RANDOM);
    }

};

const ll sz = 2e5 + 5;
vector<pair<ll, ll>> g[sz];
priority_queue<ll, vector<ll>> dist[sz];
ll cnt[sz];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    for (int i=1; i<=n; i++) dist[i].push(INT64_MAX);

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0, 1});
    dist[1].push(0);

    vector<ll> ans;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (cnt[u] >= k) continue;
        cnt[u]++;

        if (u == n) ans.push_back(d);

        for (auto &[v, w]: g[u]) {
            if (cnt[v] >= k) continue;
            pq.push({d + w, v});
        }
    }

    for (auto &i: ans) cout << i << ' ';

    return 0;
}
