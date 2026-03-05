#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    const ll inf = INT64_MAX;
    vector<vector<pair<ll, ll>>> v(n+1);
    vector<ll> dist(n+1, inf);
    for (int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    dist[1]=0;
    while (!pq.empty()) {
        auto [d, at] = pq.top(); pq.pop();
        if (-d>dist[at]) continue;
        for (auto &[to, w]: v[at]) {
            if (-d+w<dist[to]) {
                dist[to]=-d+w;
                pq.push({-dist[to], to});
            }
        }
    }
    for (int i=1; i<=n; i++) cout << dist[i] << ' ';

    return 0;
}
