#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int find(vector<int>& par, int a) {
    if (par[a] != a) return par[a] = find(par, par[a]);
    return a;
}

void merge(vector<int>& par, int a, int b) {
    par[find(par, a)] = par[find(par, b)];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<tuple<ll ,ll ,ll>> v(m);
    for (auto &[w, a, b]: v) cin >> a >> b >> w;
    sort(v.begin(), v.end());

    vector<int> par(n+1);
    iota(par.begin(), par.end(), 0);
    ll cost=0, cnt=0;
    for (int i=0; i<m; i++) {
        auto &[w, a, b] = v[i];
        if (find(par, a) == find(par, b)) continue;
        merge(par, a, b);
        cost += w;
        if (++cnt==n-1) break;
    }
    if (cnt!=n-1) cout << "IMPOSSIBLE";
    else cout << cost;

    return 0;
}
