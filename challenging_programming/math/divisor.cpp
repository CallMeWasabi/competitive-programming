#include <bits/stdc++.h>
#include <ios>
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

    ll n;
    cin >> n;
    ll ns=0,
    for (auto &[f, s]: v) {
        cin >> f >> s;

    }

    return 0;
}
