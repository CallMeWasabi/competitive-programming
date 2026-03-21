#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll k, n, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    // gen first window
    map<ll, ll> mp;
    queue<ll> r;
    mp[x]++;
    r.push(x);

    ll i=1;
    while (i<k) {
        x=((a%c)*(x%c)%c + (b%c))%c;
        mp[x]++;
        r.push(x);
        i++;
    }

    auto it=mp.begin();
    ll mn=it->first, cnt=it->second;
    ll ans=mn;
    while (i<n) {
        ll t=r.front(); r.pop();
        if (t==mn&&--cnt==0) {
            mp.erase(mn);
            auto it=mp.begin();
            mn=it->first, cnt=it->second;
        }
        x=((a%c)*(x%c)%c + (b%c))%c;
        mp[x]++;
        r.push(x);
        ans^=mn;
        i++;
    }

    cout << ans;

    return 0;
}
