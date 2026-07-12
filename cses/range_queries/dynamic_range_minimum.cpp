#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<int> vec, tr;
int combine(int a, int b) { return min(a, b); }

void update(int idx, int val, int i=0, int l=0, int r=n-1) {
    if (l==r) {
        tr[i] = val;
        return;
    }

    int m = (l+r)/2;
    if (idx <= m) update(idx, val, i*2+1, l, m);
    else update(idx, val, i*2+2, m+1, r);

    tr[i] = combine(tr[i*2+1], tr[i*2+2]);
}

int query(int ql, int qr, int i=0, int l=0, int r=n-1) {
    if (ql > r || qr < l) return 1e9+1;
    if (ql <= l && r <= qr) return tr[i];

    int m = (l+r)/2;
    return combine(query(ql, qr, i*2+1, l, m), query(ql, qr, i*2+2, m+1, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> q;
    vec.assign(n, 1e9+1);
    tr.assign(4*n, 1e9+1);
    for (auto &i: vec) cin >> i;
    for (int i=0; i<n; i++) update(i, vec[i]);
    while (q--) {
        int c;
        cin >> c;
        if (c==1) {
            int k, u;
            cin >> k >> u;
            update(k-1, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(a-1, b-1) << endl;
        }
    }

    return 0;
}
