#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

ll mpow(ll base, ll expo, ll m) {
    if (expo==1) return base;
    ll r = mpow(base, expo/2, m);
    if (expo%2) return (((r%m)*(r%m))%m*(base%m))%m;
    return ((r%m)*(r%m))%m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    int m=1e9+7;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (c==0) cout << a << '\n';
        else {
            int p=mpow(b, c, m-1);
            if (p==0) cout << 1 << '\n';
            else cout << mpow(a, p, m) << '\n';
        }
    }

    return 0;
}
