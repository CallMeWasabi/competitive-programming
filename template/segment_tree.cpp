#include <iostream>
#include <vector>
#include "debugging.h"
using namespace std;

// easy segment tree implementation for finding sum query
const int N=100;
vector<int> in;
vector<int> tr;

void build(vector<int>& in, int l, int r, int i) {
    if (r - l == 1) {
        tr[i]=in[l];
        return;
    }
    int m = (l + r)/2;
    build(in, l, m, i * 2);
    build(in, m, r, i * 2 + 1);
    tr[i]=tr[i * 2]+tr[i * 2 + 1];
}

int query(int ql, int qr, int l, int r, int i=1) {
    if (ql <= l && r <= qr) return tr[i];
    if (qr <= l || ql >= r) return 0;
    int m = (l + r) / 2;
    return query(ql, qr, l, m, i * 2) + query(ql, qr, m, r, i * 2 + 1);
}

void update(int i, int v, int l, int r, int idx=1) {
    if (r - l == 1) {
        tr[idx] = in[i] = v;
        return;
    }
    int m = (l + r) /2;
    if (i < m) update(i, v, l, m, idx * 2);
    else update(i, v, m, r, idx * 2 + 1);
    tr[idx] = tr[idx * 2] + tr[idx * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    in = { 1, 2, 3, 4, 5, 6, 7, 8};
    tr.resize(in.size() * 4);
    build(in, 0, in.size(), 1);


    cout << tr << '\n';
    update(0, 7, 0, in.size());
    cout << tr << '\n';
}
