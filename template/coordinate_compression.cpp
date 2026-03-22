#include <algorithm>
#include <iostream>
#include <map>
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

    vector<ll> cp(v);
    map<ll, ll> mp;
    sort(cp.begin(), cp.end());
    auto it = unique(cp.begin(), cp.end());
    cp.erase(it, cp.end());

    for (int i=0; i<cp.size(); i++) mp[cp[i]]=i;
    for (int i=0; i<v.size(); i++) v[i] = mp[v[i]];

    return 0;
}

