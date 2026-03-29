#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

// solved

ll MN=INT32_MAX;
int n, c=0;
vector<ll> v;

void solve(int i, ll l, ll r) {
    if (i==n) {
        MN=min(MN, abs(l-r));
        return;
    }

    solve(i+1, l+v[i], r);
    solve(i+1, l, r+v[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n);
    for (auto &i: v) cin >> i;

    solve(0, 0, 0);

    cout << MN;

    return 0;
}
