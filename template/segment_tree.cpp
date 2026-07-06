#include <iostream>
#include <vector>
using namespace std;

// easy segment tree implementation for finding sum query
const int N=100;
vector<int> in;
vector<int> tr;

void build(vector<int>& in, int l, int r, int i) {
    if (r-l==1) {
        tr[i]=in[l];
        return;
    }
    int m=(l+r)/2;
    build(in, l, m, i<<1);
    build(in, m, r, i<<1|1);
    tr[i]=tr[i<<1]+tr[i<<1|1];
}

int query(int ql, int qr, int i=1, int l=0, int r=in.size()) {
    if (ql<=l&&r<=qr) return tr[i];
    if (qr<=l||ql>=r) return 0;
    int m=(l+r)/2;
    return query(ql, qr, i<<1, l, m) + query(ql, qr, i<<1|1, m, r);
}

void update(int i, int v, int idx=1, int l=0, int r=in.size()) {
    if (r-l==1) {
        tr[idx]=in[i]=v;
        return;
    }
    int m=(l+r)/2;
    if (i<m) update(i, v, idx<<1, l, m);
    else update(i, v, idx<<1|1, m, r);
    tr[idx]=tr[idx<<1]+tr[idx<<1|1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    in = { 1, 2, 3, 4, 5, 6, 7, 8};
    tr.resize(in.size()*4);
    build(in, 0, in.size(), 1);

    for (auto &i: tr) cout << i << ' ';
    cout << endl;
    // cout << query(0, 2, 1, 0);
    update(0, 7);
    for (auto &i: tr) cout << i << ' ';
}
