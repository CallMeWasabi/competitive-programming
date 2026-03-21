#include <bits/stdc++.h>
#include <sys/syslimits.h>
using namespace std;
using ll = long long;

const ll m = 1e9+7;

ll mpow(ll base, ll expo) {
    if (expo==1) return base;
    ll r = mpow(base, expo/2);
    if (expo%2) return (((r%m)*(r%m))%m*(base%m))%m;
    return ((r%m)*(r%m))%m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (b==0) cout << 1LL << '\n';
        else cout << mpow(a, b)%m << '\n';
    }


    return 0;
}

// a^p-2 = a^-1 mod p
