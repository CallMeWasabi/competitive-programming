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

    vector<pair<ll, ll>> v(n);
    for (auto &[a, b]: v) cin >> a >> b;

    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
        return a.second < b.second;
    });

    int c=0, l=0;
    for (auto &[a, b]: v) if (a>=l) c++, l=b;

    cout << c;

    return 0;
}
