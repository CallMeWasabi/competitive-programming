#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;

    vector<ll> k(n);
    ll mn=1e9;
    for (auto &i: k) cin >> i, mn=min(mn, i);
    ll l=1, r=mn*t+1;
    while (l<r) {
        ll m=(l+r)/2; // random time
        ll p=0;
        for (auto &i: k) p += m/i;
        if (p>=t) r=m;
        else l=m+1;
    }
    cout << l;

    return 0;
}
