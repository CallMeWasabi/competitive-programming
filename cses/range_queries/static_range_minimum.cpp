#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<int> arr, tr;

int combine(int a, int b) {
    return min(a, b);
}

void build(int i=0, int l=0, int r=n-1) {
    if (l == r) tr[i] = arr[l];
    else {
        int m = (l+r)/2;
        build(i*2+1, l, m);
        build(i*2+2, m+1, r);

        tr[i] = combine(tr[i*2+1], tr[i*2+2]);
    }
}

void update(int idx, int val, int i=0, int l=0, int r=n-1) {
    if (l==r) tr[i] = arr[l] = val;
    else {
        int m = (l+r)/2;
        if (idx <= m) update(idx, val, i*2+1, l, m);
        else update(idx, val, i*2+2, m+1, r);

        tr[i] = combine(tr[i*2+1], tr[i*2+2]);
    }
}

int query(int ql, int qr, int i=0, int l=0, int r=n-1) {
    if (ql > r || qr < l) return 1e9+1;
    if (ql <= l && r <= qr) return tr[i];
    int m = (l+r)/2;

    return combine(query(ql, qr, i*2+1, l, m), query(ql, qr, i*2+2, m+1, r));
}

int main() {
    cin >> n >> q;

    arr.assign(n, 1e9+1);
    tr.assign(4*n, 1e9+1);
    for (auto &i: arr) cin >> i;
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r) << '\n';
    }

    return 0;
}
