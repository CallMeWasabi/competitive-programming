#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> v, seg;

void build(vector<ll>& seg, int l, int r, int i) {
    if (r - l == 1) {
        seg[i] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(seg, l, m, i * 2);
    build(seg, m, r, i * 2 + 1);
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

ll query(vector<ll>& seg, int ql, int qr, int l, int r, int i) {
    if (l <= ql && qr <= r) return seg[i];
    else if (l >= qr || r <= ql) return 0;
    int m = (l + r) / 2;
    return query(seg, ql, qr, l, m, i * 2) + query(seg, ql, qr, m, r, i * 2 + 1);
}

void update(vector<ll>& seg, int idx, int v, int l, int r, int i) {
    if (r - l == 1) {
        seg[i] = v;
        return;
    }
    int m = (l + r) / 2;
    if (idx < m) update(seg, idx, v, l, m, i * 2);
    else update(seg, idx, v, m, r, i * 2 + 1);
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

ll kth(vector<ll>& seg, int l, int r, int i, ll k) {
    if (r - l == 1) return l;
    int m = (l + r) / 2;
    ll cnt_l = seg[i * 2];
    if (k <= cnt_l) return kth(seg, l, m, i * 2, k);
    else return kth(seg, m, r, i * 2 + 1, k - cnt_l);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    v.assign(n, 0);
    seg.assign(4 * n, 0);

    for (auto &i: v) cin >> i;
    build(seg, 0, n, 1);

    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        ll pos = kth(seg, 0, n, 1, k);
        update(seg, pos, 0, 0, n, 1);
        cout << v[pos] << ' ';
    }

    return 0;
}
