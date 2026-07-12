#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i: v) cin >> i;

    sort(v.begin(), v.end());
    ll m = v.size() / 2;
    ll s = 0;

    for (auto &i: v) s += abs(i - v[m]);

    cout << s;

    return 0;
}
