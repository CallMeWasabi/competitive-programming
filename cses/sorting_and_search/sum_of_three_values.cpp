#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    map<ll, vector<ll>> mp;
    vector<ll> v(n);

    for (int i=0; i<n; i++) cin >> v[i], mp[v[i]].push_back(i+1);

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ll k = v[i] + v[j];
            ll r = x-k;
            if (r < 0 || mp[r].empty()) continue;

            for (auto &w: mp[r]) {
                if (w!=i+1 && w!=j+1) {
                    cout << i+1 << ' ' << j+1 << ' ' << w;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
