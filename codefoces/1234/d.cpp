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
#include <array>
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

    string s;
    cin >> s;

    int sz = s.length();

    vector<array<int, 26>> b(sz, array<int, 26>());
    b.reserve(sz);
    for (int i=0; i<sz; i++) b[i].fill(0), b[i][s[i]-'a']++;

    SegmentTree<array<int, 26>> seg = SegmentTree<array<int, 26>>(
        b,
        [](array<int, 26> a, array<int, 26> b) {
            array<int, 26> c = { 0 };
            for (int i=0; i<26; i++) c[i] = a[i] + b[i];
            return c;
        },
        []() {
            array<int, 26> c = { 0 };
            return c;
        }
    );

    int m;
    cin >> m;
    while (m--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            char y;
            cin >> y;
            array<int, 26> arr = { 0 };
            arr[y - 'a']++;
            seg.update(x-1, arr, 0, sz, 1);
        } else {
            int y;
            cin >> y;
            auto k = seg.query(x-1, y, 0, sz, 1);
            int cnt = 0;
            for (int i=0; i<26; i++) if (k[i] > 0) cnt++;
            cout << cnt << '\n';
        }
    }

    return 0;
}
