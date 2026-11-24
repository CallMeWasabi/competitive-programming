
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;
using int128 = __int128;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;

    vector<ll> v(n);
    for (auto &i: v) cin >> i;
    sort(v.begin(), v.end());

    ll cnt = 0;
    int i = 0, j = n-1;
    for (; i<=j;) {
        if (i == j) {
            i++, cnt++;
        } else if (v[i] + v[j] <= x) {
            i++, j--, cnt++;
        } else {
            j--, cnt++;
        }
    }

    cout << cnt;
}
