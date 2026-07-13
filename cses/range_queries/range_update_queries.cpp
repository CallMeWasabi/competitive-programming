#include <iostream>
#include <vector>
#define Identity 1e9+1
using namespace std;

typedef long long ll;

ll n, q;
vector<ll> arr, tr;

ll combine(ll a, ll b) { return a + b; }

void build(int i=0, int l=0, int r=n-1) {
    if (l==r) {
        tr[i] = arr[l];
        return;
    }

    ll m = (l+r)/2;
    build(i*2+1, l, m);
    build(i*2+2, m+1, r);

    tr[i] = combine(tr[i*2+1], tr[i*2+2]);
}

void update(int idx, ll val, int i=0, int l=0, int r=n-1) {
    if (l==r) {
        tr[i] += val;
        arr[l] += val;
        return;
    }

    ll m = (l+r)/2;
    if (idx <= m) update(idx, val, i*2+1, l, m);
    else update(idx, val, i*2+2, m+1, r);

    tr[i] = combine(tr[i*2+1], tr[i*2+2]);
}

ll query(int ql, int qr, int i=0, int l=0, int r=n-1) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tr[i];

    ll m = (l+r)/2;

    return combine(query(ql, qr, i*2+1, l, m), query(ql, qr, i*2+2, m+1, r));
}

int main() {
    cin >> n >> q;

    arr.assign(n, 0);
    tr.assign(4*n, 0);
    for (auto &i: arr) cin >> i;
    for (int i=n-1; i>0; i--) arr[i] -= arr[i-1];
    // for (int i=0; i<n; i++) update(i, arr[i]);
    build();
    while (q--) {
        int c;
        cin >> c;
        if (c==1) {
            ll a, b, u;
            cin >> a >> b >> u;
            a--, b--;
            update(a, +u);
            if (b<n-1) update(b+1, -u);
        } else {
            ll k;
            cin >> k;
            cout << query(0, k-1) << '\n';
        }
    }
}
