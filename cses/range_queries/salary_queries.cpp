#include <algorithm>
#include <ios>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

// solved 22/03/2026

const int N = 2e5+5;
vector<int> tr;

void build(vector<int> const& in, int i, int l, int r) {
    if (r-l==1) {
        tr[i]=in[l];
        return;
    }
    int m=(l+r)/2;
    build(in, i<<1, l, m);
    build(in, i<<1|1, m, r);
    tr[i]=tr[i<<1] + tr[i<<1|1];
}

int query(int ql, int qr, int i, int l, int r) {
    if (ql<=l && r<=qr) return tr[i];
    else if (qr<=l || ql>=r) return 0;
    int m=(l+r)/2;
    return query(ql, qr, i<<1, l, m) + query(ql, qr, i<<1|1, m, r);
}

void add(int ind, int v, int i, int l, int r) {
    if (r-l==1) {
        tr[i]+=v;
        return;
    }
    int m=(l+r)/2;
    if (ind<m) add(ind, v, i<<1, l, m);
    else add(ind, v, i<<1|1, m, r);
    tr[i]=tr[i<<1]+tr[i<<1|1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> cp;
    vector<tuple<char, int, int>> ask(q);
    cp.reserve(N*2);
    for (auto &i: v) cin >> i, cp.push_back(i);
    for (auto &[c, a, b]: ask) {
        cin >> c >> a >> b;
        if (c=='!') cp.push_back(b);
    }

    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    map<int, int> mp;
    for (int i=0; i<cp.size(); i++) mp[cp[i]]=i;

    vector<int> in(cp.size());
    for (int i=0; i<v.size(); i++) in[mp[v[i]]]++;

    tr.resize(in.size()*4);
    build(in, 1, 0, in.size());

    for (auto &[c, a, b]: ask) {
        if (c=='!') {
            int prev=v[a-1];
            add(mp[prev], -1, 1, 0, in.size());
            add(mp[b], 1, 1, 0, in.size());
            v[a-1]=b;
        } else {
            int ql = lower_bound(cp.begin(), cp.end(), a) - cp.begin();
            int qr = upper_bound(cp.begin(), cp.end(), b) - cp.begin();
            cout << query(ql, qr, 1, 0, in.size()) << '\n';
        }
    }

    return 0;
}
