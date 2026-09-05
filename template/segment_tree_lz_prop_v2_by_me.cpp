#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

const int sz = 2e5 + 5;

struct ST {
    int n;
    vector<ll> tr;
    vector<ll> lazy;

    ST(const vector<ll>& a) {
        n = (int)a.size();
        tr.assign(n * 4, 0);
        lazy.assign(n * 4, 0);
        build(a, 0, n);
    }

    void pull(int i) {
        tr[i] = tr[i * 2] + tr[i * 2 + 1];
    }

    void build(const vector<ll>& a, int l, int r, int i = 1) {
        if (r - l == 1) {
            tr[i] = a[l];
            return;
        }

        int m = (l+r)/2;
        build(a, l, m, i*2);
        build(a, m, r, i*2+1);

        pull(i);
    }

    void apply(ll v, int l, int r, int i) {
        tr[i] += (r-l) * v;
        lazy[i] += v;
    }

    void push(int l, int r, int i) {
        if (lazy[i] == 0 || r - l == 1) return;

        int m = (l+r)/2;
        apply(lazy[i], l, m, i*2);
        apply(lazy[i], m, r, i*2+1);

        lazy[i] = 0;
    }

    void range_add(int ql, int qr, ll v, int l, int r, int i = 1) {
        if (r <= ql || l >= qr) return;
        if (ql <= l && r <= qr) {
            apply(v, l, r, i);
            return;
        }

        push(l, r, i);
        int m = (l+r)/2;

        range_add(ql, qr, v, l, m, i * 2);
        range_add(ql, qr, v, m, r, i * 2 + 1);

        pull(i);
    }

    ll query(int ql, int qr, int l, int r, int i = 1) {
        if (r <= ql || l >= qr) return 0;
        if (ql <= l && r <= qr) return tr[i];

        push(l, r, i);
        int m = (l+r)/2;

        return query(ql, qr, l, m, i * 2) + query(ql, qr, m, r, i * 2 + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (auto &i: arr) cin >> i;

    ST st = ST(arr);

    while (q--) {
        ll x, a, b, u, k;
        cin >> x;
        if (x == 1) {
            cin >> a >> b >> u;
            st.range_add(a-1, b, u, 0, n);
        } else {
            cin >> k;
            ll ans = st.query(k-1, k, 0, n);
            cout << ans << '\n';
        }
    }

    return 0;
}
