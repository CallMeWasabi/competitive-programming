#include <cstdint>
#include <iostream>
#include <cmath>
using namespace std;

void solve(int n) {
    typedef long long ll;
    ll l=1, r=INT32_MAX;
    while (l<r) {
        ll m=(l+r)/2;
        if (log(n)/log(m))
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        solve(n);
    }
}
