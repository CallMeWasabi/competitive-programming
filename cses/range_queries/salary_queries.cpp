#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

// NOTE: may be using lazy propagation to avoid time limit

struct Interval {
    ll left, right, cnt;

    Interval() {}
    Interval(ll l, ll r, ll c):
        left(l), right(r), cnt(c) {}
};

Interval combine(Interval& l, Interval& r) {
    return Interval(
        min(l.left, r.left),
        max(l.right, r.right),
        l.cnt + r.cnt
    );
}

vector<ll> in;
vector<Interval> tr;

// # [debug]
string to_string(Interval& inter) {
    return "{left={" + to_string(inter.left) + "}, right={" + to_string(inter.right) + "}, cnt={" + to_string(inter.cnt) + "}}";
}

void build(vector<ll>& in, int l, int r, int i) {
    if (r-l==1) {
        tr[i]=Interval(in[l], in[l], 1);
        return;
    }
    int m=(l+r)/2;
    build(in, l, m, i<<1);
    build(in, m, r, i<<1|1);
    tr[i]=combine(tr[i<<1], tr[i<<1|1]);
}

int query(int a, int b, int i=1, int l=0, int r=in.size()) {
    if (a<=tr[i].left && tr[i].right<=b) return tr[i].cnt;
    if (tr[i].right<a || tr[i].left>b) return 0;
    int m = (l+r)/2;
    return query(a, b, i<<1, l, m) + query(a, b, i<<1|1, m, r);
}

void update(int i, int v, int idx=1, int l=0, int r=in.size()) {
    if (r-l==1) {
        tr[idx].left=tr[idx].right=in[i]=v;
        return;
    }
    int m=(l+r)/2;
    if (i<m) update(i, v, idx<<1, l, m);
    else update(i, v, idx<<1|1, m, r);
    tr[idx]=combine(tr[idx<<1], tr[idx<<1|1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    in.resize(n);
    tr.resize(in.size()*4);

    for (auto &i: in) cin >> i;
    build(in, 0, in.size(), 1);

    char c;
    while (q--) {
        cin >> c;
        if (c=='!') {
            ll k, x;
            cin >> k >> x;
            update(k-1, x);
        } else {
            ll a ,b;
            cin >> a >> b;
            cout << query(a, b) << '\n';
        }
    }

    return 0;
}
