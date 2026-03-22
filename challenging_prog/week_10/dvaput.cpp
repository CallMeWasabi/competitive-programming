#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

// hash
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll P1 = 31;
const ll P2 = 37;

int L;
string s;
const ll sz=2e5+5;
ll pow1[sz], pow2[sz];
ll h1[sz], h2[sz];

pair<ll, ll> get_hash(int l, int r) {
    ll res1 = (h1[r + 1] - h1[l] * pow1[r - l + 1] % mod1 + mod1) % mod1;
    ll res2 = (h2[r + 1] - h2[l] * pow2[r - l + 1] % mod2 + mod2) % mod2;
    return {res1, res2};
}

bool check(int len) {
    if (len==0) return 1;
    vector<pair<ll, ll>> seen;
    for (int i=0; i<=L-len; i++) seen.push_back(get_hash(i, i + len - 1));
    sort(seen.begin(), seen.end());
    for (int i=1; i<seen.size(); i++) if (seen[i]==seen[i-1]) return 1;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> L >> s;
    pow1[0]=pow2[0]=1;
    for (int i=1; i<=L; i++) {
        pow1[i]=(pow1[i-1] * P1) % mod1;
        pow2[i]=(pow2[i-1] * P2) % mod2;
    }
    for (int i=0; i<L; i++) {
        h1[i+1]=(h1[i]*P1+(s[i]-'a'+1)) % mod1;
        h2[i+1]=(h2[i]*P2+(s[i]-'a'+1)) % mod2;
    }

    ll l=0, r=L+1;
    while (l<r) {
        ll m = (l+r)/2;
        if (check(m)) l=m+1;
        else r=m;
    }

    cout << l-1;

    return 0;
}
