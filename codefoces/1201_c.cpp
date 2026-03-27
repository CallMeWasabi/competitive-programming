#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (auto &i: v) cin >> i;

    sort(v.begin(), v.end());
    ll l=1, r=2e9+7;
    while (l<r) {
        ll m = (l+r)/2;
        ll c=0;
        for (int i=n/2; i<n; i++) c += max(0LL, m-v[i]);
        if (c<=k) l=m+1;
        else r=m;
    }

    cout << l-1;

    return 0;
}
