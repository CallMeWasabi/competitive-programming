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
        int c;
        cin >> c;
        if (c==1) {
            int k, u;
            cin >> k >> u;
            k--;
            update(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << query(a, b) << '\n';
        }
    }

    return 0;
