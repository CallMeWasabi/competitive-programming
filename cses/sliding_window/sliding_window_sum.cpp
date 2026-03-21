#include <bits/stdc++.h>
#include <ios>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll k, n, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    // gen first window
    ll acc=x, i=1;
    queue<ll> r;
    r.push(x);
    while (i<k) {
        x=((a%c)*(x%c)%c + (b%c))%c;
        r.push(x);
        acc+=x;
        i++;
    }

    ll ans=acc;
    while (i<n) {
        acc -= r.front(); r.pop();
        x=((a%c)*(x%c)%c + (b%c))%c;
        acc+=x;
        r.push(x);
        ans^=acc;
    }

    cout << ans;

    return 0;
}
