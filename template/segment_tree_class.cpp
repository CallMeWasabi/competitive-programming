#include <vector>
#include <functional>
using namespace std;

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
