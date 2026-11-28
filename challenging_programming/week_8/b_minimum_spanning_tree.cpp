#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int find(vector<int>& par, int a) {
    if (par[a]==a) return a;
    return par[a]=find(par, par[a]);
}

bool same(vector<int>& par, int a, int b) {
    return find(par, a) == find(par, b);
}

void merge(vector<int>& par, int a, int b) {
    par[find(par, a)] = par[find(par, b)];
}

void solve(int n, int m) {
    vector<tuple<int, int, int>> e(m);
    vector<int> par(n);
    iota(par.begin(), par.end(), 0);

    for (auto &[w, a, b]: e) cin >> a >> b >> w;
    sort(e.begin(), e.end());

    int cost=0;
    vector<pair<int, int>> ans;
    for (int i=0; i<e.size(); i++) {
        auto &[w, a, b] = e[i];
        if (same(par, a, b)) continue;

        cost+=w;
        merge(par, a, b);
        ans.push_back({min(a, b), max(a, b)});
        if (ans.size()==n-1) break;
    }

    if (ans.size()!=n-1) cout << "Impossible\n";
    else {
        sort(ans.begin(), ans.end());
        cout << cost << '\n';
        for (auto &[a, b]: ans) cout << a << ' ' << b << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (1) {
        int n, m;
        cin >> n >> m;
        if (n==m&&n==0) break;
        solve(n, m);
    }
}
