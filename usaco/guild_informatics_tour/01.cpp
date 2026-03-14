#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    ll mx=0;
    for (auto &[f, s]: v) cin >> f >> s, mx=max(mx, f);
    ll l=0, r=mx+1;
    while (l<r) {
        ll m=(l+r)/2;
        ll cnt=m;
        bool pos=1;
        for (auto &[f, s]: v) {
            if (cnt>=f) cnt+=s;
            else {
                pos=0;
                break;
            }
        }
        if (pos) r=m;
        else l=m+1;
    }
    cout << l;



    return 0;
}
