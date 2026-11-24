#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;
using int128 = __int128;

#define debug(x) cerr << #x << ": " << x << '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;

    vector<ll> v(n);
    for (auto &i: v) cin >> i;

    map<ll, ll> mp;
    mp[0] = 1;

    ll cur = 0, cnt = 0;
    for (int i=0; i<n; i++) {
        cur += v[i];
        cnt += mp[cur - x];
        mp[cur]++;
    }

    cout << cnt;

    return 0;
}
