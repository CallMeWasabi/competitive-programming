#include <iostream>
#include <vector>
using namespace std;

long long n, q;
vector<long long> arr, tr;

long long combine(long long a, long long b) {
    return a + b;
}

void build(long long i=0, int l=0, int r=n-1) {
    if (l == r) tr[i] = arr[l];
    else {
        long long m = (l+r)/2;
        build(i*2+1, l, m);
        build(i*2+2, m+1, r);

        tr[i] = combine(tr[i*2+1], tr[i*2+2]);
    }
}

void update(long long idx, int val, int i=0, int l=0, int r=n-1) {
    if (l==r) tr[i] = arr[l] = val;
    else {
        long long m = (l+r)/2;
        if (idx <= m) update(idx, val, i*2+1, l, m);
        else update(idx, val, i*2+2, m+1, r);

        tr[i] = combine(tr[i*2+1], tr[i*2+2]);
    }
}

long long query(int ql, int qr, int i=0, int l=0, int r=n-1) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tr[i];
    long long m = (l+r)/2;

    return combine(query(ql, qr, i*2+1, l, m), query(ql, qr, i*2+2, m+1, r));
}

int main() {
    cin >> n >> q;

    arr.assign(n, 0);
    tr.assign(4*n, 0);
    for (auto &i: arr) cin >> i;
    build();
    while (q--) {
        long long l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r) << '\n';
    }

    return 0;
