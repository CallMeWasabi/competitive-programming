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
    int i=0, j=n-1;
    ll l=0, r=0;
    while (i<n && j>-1) {

    }

    return 0;
}
