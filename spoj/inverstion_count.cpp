#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void update(vector<ll>& tr, int i, int v, int l, int r, int tr_idx=1) {
    if (r - l == 1) {
        tr[tr_idx] += v;
        return;
    }

    int m = (l + r) / 2;
    if (i < m) update(tr, i, v, l, m, tr_idx * 2);
    else update(tr, i, v, m, r, tr_idx * 2 + 1);
    tr[tr_idx] = tr[tr_idx * 2] + tr[tr_idx * 2 + 1];
}

ll query(vector<ll>& tr, int ql, int qr, int l, int r, int i=1) {
    if (ql <= l && r <= qr) return tr[i];
    else if (qr <= l || ql >= r) return 0;

    int m = (l + r) / 2;
    return query(tr, ql, qr, l, m, i * 2) + query(tr, ql, qr, m, r, i * 2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    string s;
    cin >> t;
    getline(cin, s);
    while (t--) {
        int n;
        cin >> n;
        vector<ll> in(n);
        for (auto &i: in) cin >> i;
        getline(cin, s);

        vector<ll> cp(in);
        map<int, int> mp;
        sort(cp.begin(), cp.end());
        int idx=1;
        for (auto &k: cp) if (mp.count(k) == 0) mp[k] = idx++;
        for (int i=0; i<in.size(); i++) in[i] = mp[in[i]];

        vector<ll> tr(n * 4 + 1, 0);
        ll cnt = 0;
        for (auto &k: in) {
            cnt += query(tr, k+1, idx, 0, n+1);
            update(tr, k, 1, 0, n+1);
        }

        cout << cnt << '\n';
    }

    return 0;
}
