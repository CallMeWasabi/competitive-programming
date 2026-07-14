#include <iostream>
#include <vector>

using namespace std;

// Easy segment tree implementation for finding sum query with lazy propagation
vector<int> in;
vector<int> tr;
vector<int> lz;

// Build the initial segment tree
void build(const vector<int>& in, int l, int r, int idx) {
    if (r - l == 1) {
        tr[idx] = in[l];
        return;
    }
    int m = (l + r) / 2;
    build(in, l, m, idx * 2);
    build(in, m, r, idx * 2 + 1);
    tr[idx] = tr[idx * 2] + tr[idx * 2 + 1];
}

// Push pending lazy updates down to the children nodes
void push(int l, int r, int idx) {
    if (lz[idx] == 0) return; // Nothing to propagate

    int m = (l + r) / 2;

    // Propagate lazy values to children
    lz[idx * 2] += lz[idx];
    tr[idx * 2] += lz[idx] * (m - l);

    lz[idx * 2 + 1] += lz[idx];
    tr[idx * 2 + 1] += lz[idx] * (r - m);

    // Reset the current node's lazy value
    lz[idx] = 0;
}

// Range Update: Adds 'v' to all elements in the range [ul, ur)
void update(int ul, int ur, int v, int l, int r, int idx = 1) {
    // Total overlap
    if (ul <= l && r <= ur) {
        tr[idx] += v * (r - l);
        if (r - l > 1) { // If not a leaf node, defer to children
            lz[idx] += v;
        }
        return;
    }
    // No overlap
    if (ur <= l || ul >= r) return;

    // Partial overlap: Push down changes before recursing
    push(l, r, idx);

    int m = (l + r) / 2;
    update(ul, ur, v, l, m, idx * 2);
    update(ul, ur, v, m, r, idx * 2 + 1);

    tr[idx] = tr[idx * 2] + tr[idx * 2 + 1];
}

// Range Query: Returns the sum of elements in the range [ql, qr)
int query(int ql, int qr, int l, int r, int idx = 1) {
    // Total overlap
    if (ql <= l && r <= qr) return tr[idx];
    // No overlap
    if (qr <= l || ql >= r) return 0;

    // Partial overlap: Push down changes before recursing
    push(l, r, idx);

    int m = (l + r) / 2;
    return query(ql, qr, l, m, idx * 2) + query(ql, qr, m, r, idx * 2 + 1);
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // Sample Input
    in = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = in.size();

    // Allocate memory for tree and lazy arrays (4 * N rule of thumb)
    tr.assign(n * 4, 0);
    lz.assign(n * 4, 0);

    build(in, 0, n, 1);

    // 1. Initial sum of range [0, 4) -> 1 + 2 + 3 + 4 = 10
    cout << "Initial sum [0, 4): " << query(0, 4, 0, n) << '\n';

    // 2. Add 5 to every element in the range [0, 4)
    // New values will effectively be: {6, 7, 8, 9, 5, 6, 7, 8}
    update(0, 4, 5, 0, n);

    // 3. Query after range update -> 6 + 7 + 8 + 9 = 30
    cout << "Sum [0, 4) after update: " << query(0, 4, 0, n) << '\n';

    // 4. Query another overlapping segment [2, 6) -> 8 + 9 + 5 + 6 = 28
    cout << "Sum [2, 6) after update: " << query(2, 6, 0, n) << '\n';

    return 0;
}
