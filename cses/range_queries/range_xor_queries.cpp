#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> vec, tr;

ll combine(ll a, ll b) { return a^b; }
void update(int idx, ll val, int i, int l, int r) {
    if (l==r) tr[i]=val;
    else {
        int m = l + (r - l)/2;
        if (idx<=m) update(idx, val, i*2+1, l, m);
        else update(idx, val, i*2+2, m+1, r);

        tr[i] = combine(tr[i*2+1], tr[i*2+2]);
    }
}

ll query(int ql, int qr, int i, int l, int r) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tr[i];

    int m = l + (r - l)/2;
    return combine(query(ql, qr, i*2+1, l, m), query(ql, qr, i*2+2, m+1, r));
}

int main() {
    int n, q;
    cin >> n >> q;
    vec.assign(n, 0);
    tr.assign(4*n, 0);
    for (auto &i: vec) cin >> i;
    for (ll i=0; i<n; i++) update(i, vec[i], 0, 0, n-1);
    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << query(a-1, b-1, 0, 0, n-1) << endl;
    }
}
