#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

inline int dist(pair<int, int> a, pair<int, int> b) {
    auto &[x1, y1] = a;
    auto &[x2, y2] = b;
    return pow(x2-x1, 2) + pow(y2-y1, 2);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[i, _]: v) cin >> i;
    for (auto &[_, i]: v) cin >> i;
    int mx=0;
    for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) mx=max(mx, dist(v[i], v[j]));
    cout << mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    solve();

    return 0;
}
