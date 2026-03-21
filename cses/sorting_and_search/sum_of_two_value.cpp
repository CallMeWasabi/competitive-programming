#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
    ll n, x;
    cin >> n >> x;
    map<ll, ll> m;
    map<ll, vector<ll>> p;
    for (int i=0; i<n; i++) {
        ll a;
        cin >> a;
        m[a]++;
        p[a].push_back(i+1);
    }
    for (auto &[k, v]: m) {
        if (k>=x) continue;
        ll r = x-k;
        if (m.count(r) > 0) {
            if (r==k) {
                if (p[k].size()==1) continue;
                cout << p[k][0] << ' ' << p[k][1];
                return;
            }
            cout << min(p[k][0], p[r][0]) << ' ' << max(p[k][0], p[r][0]);
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();

    return 0;
}
