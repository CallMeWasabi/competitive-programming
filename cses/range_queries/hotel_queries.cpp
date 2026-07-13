#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> vec, tr;

int n, m;

ll combine(ll a, ll b) { return max(a, b); }

void update(int idx, ll val, int i=0, int l=0, int r=n-1) {
    if (l==r) { tr[i]+=val; return;}
    ll m = (l+r)/2;
    if (idx<=m) update(idx, val, i*2+1, l, m);
    else update(idx, val, i*2+2, m+1, r);

    tr[i]=combine(tr[i*2+1], tr[i*2+2]);
}
int query(ll val, int i=0, int l=0, int r=n-1) {
    if (val>tr[i]) return -1;
    if (l==r) {
        if (val>tr[i]) return-1;
        else return l;
    }

    ll m=(l+r)/2;
    if (val<=tr[i*2+1]) return query(val, i*2+1, l, m);
    else return query(val, i*2+2, m+1, r);
}

int main() {
    cin >> n >> m;
    vec.assign(n, 0);
    tr.assign(4*n, 0);
    for (auto &i: vec) cin >> i;
    for (int i=0; i<n; i++) update(i, vec[i]);
    while (m--) {
        ll need;
        cin >> need;
        int idx = query(need);

        if (idx==-1) cout << 0 << ' ';
        else {
            cout << idx+1 << ' ';
            update(idx, -need);
        }
    }
}
