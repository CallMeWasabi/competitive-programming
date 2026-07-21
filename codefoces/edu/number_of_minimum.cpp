
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <utility>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <numeric>
#include <functional>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;


template <typename E, typename R = E>
class SegmentTree {
public:
    vector<E> tree, arr;
    function<R(E, E)> combine;
    function<R()> identity;

    SegmentTree(
        vector<E>& ref,
        function<R(E, E)> c_func,
        function<R()> i_func = []() { return R();}
    ): combine(c_func), identity(i_func) {
        int sz = ref.size();
        arr.resize(sz, E());
        tree.resize(4 * sz, E());

        copy(ref.begin(), ref.end(), arr.begin());
        for (int i=0; i<sz; i++) update(i, ref[i], 0, sz, 1);
    }

    void update(int idx, E v, int l, int r, int i) {
        if (r-l == 1) {
            tree[i] = arr[l] = v;
            return;
        }
        int m = (l+r)/2;

        if (idx < m) update(idx, v, l, m, i*2);
        else update(idx, v, m, r, i*2+1);

        tree[i] = combine(tree[i*2], tree[i*2+1]);
    }

    R query(int ql, int qr, int l, int r, int i) {
        if (ql <= l && r <= qr) return tree[i];
        if (qr <= l || ql >= r) return identity();
        int m = (l+r)/2;
        return combine(query(ql, qr, l, m, i*2), query(ql, qr, m, r, i*2+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    for (auto &i: arr) cin >> i;

    vector<pair<ll, ll>> b(n);
    for (int i=0; i<n; i++) b[i] = {arr[i], 1};

    SegmentTree<pair<ll, ll>> seg = SegmentTree<pair<ll, ll>>(
        b,
        [](pair<ll, ll> a, pair<ll, ll> b) {
            if (a.first == b.first) return make_pair(a.first, a.second + b.second);
            return a.first < b.first ? a: b;
        },
        []() { return make_pair( 1e9 + 7, 1 ); }
    );

    while (m--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) seg.update(x, {y, 1}, 0, n, 1);
        else {
            auto p = seg.query(x, y, 0, n, 1);
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    return 0;
}
