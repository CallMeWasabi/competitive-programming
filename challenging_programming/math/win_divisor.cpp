#include <iostream>
using namespace std;
using ll = long long;

const ll m=1e9+7;

ll mpow(ll  b, ll p) {
    if (p==1) return b;
    ll r = mpow(b, p/2);
    if (p%2) return ((r%m)*(r%m)*(b%m))%m;
    return (r%m)*(r%m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll a=1, b=1, c=1;
    ll n;
    cin >> n;
    while (n--) {
        ll x, k;
        cin >> x >> k;
        a = ((a%m)*(mpow(x, k)%m))%m;
        b = ((b%m) * ((mpow(x, k+1)-1)/(x-1)))%m;
        c = ((c%m)*((k+1)%m))%m;
    }

    cout << a << ' ' << b << ' ' << mpow(a, c/2) << '\n';


    return 0;
}
