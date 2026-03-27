#include <ios>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// solved 27/03/2026

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i: v) cin >> i;

    ll l=0, r=2e14+1;
    while (l<r) {
        ll m = (l+r)/2;
        ll i=0, c=0, acc=0;
        bool impossible=0;
        while (i<n) {
            if (v[i]>m) {
                impossible=1;
                break;
            }
            else if (acc+v[i]>m) c++, acc=v[i];
            else if (acc+v[i]==m) c++, acc=0;
            else acc+=v[i];
            i++;
        }
        if (acc>m) impossible=1;
        else if (acc>0) c++;

        if (impossible ||  c>k) l=m+1;
        else r=m;
    }

    cout << l;


    return 0;
}
