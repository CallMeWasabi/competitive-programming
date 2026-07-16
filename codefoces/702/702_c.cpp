#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll l=0, r=3e9;
    while (l<r) {
        ll mid = (l+r)/2;
        ll i = 0, j = 0;
        while (i < n && j < m) {
            if (b[j] - mid <= a[i] && a[i] <= b[j] + mid) i++;
            else j++;
        }
        if (i==n) r=mid;
        else l=mid+1;
    }

    cout << l << '\n';
}
