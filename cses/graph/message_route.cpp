#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=1e5+5;
vector<ll> v[N], dist(N, 1e9), par(N);


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++ ) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    iota(par.begin(), par.end(), 0);

    queue<pair<ll, ll>> q; // town, step
    q.push({1, 1});
    dist[1]=0;
    while (!q.empty()) {
        auto [at, s] = q.front(); q.pop();
        for (auto &to: v[at]) {
            if (s+1 < dist[to]) {
                dist[to]=s+1;
                par[to]=at;
                q.push({to, dist[to]});
            }
        }
    }

    if (dist[n] == 1e9) cout << "IMPOSSIBLE";
    else {
        cout << dist[n] << '\n';
        vector<int> path;
        int i=n;
        while (i!=par[i]) {
            path.push_back(i);
            i=par[i];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        for (auto &i: path) cout << i << ' ';
    }

    return 0;
}
