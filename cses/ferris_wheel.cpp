#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &i: v) cin >> i;
    sort(v.begin(), v.end(), greater<>());
    int i=0, c=0;
    ll b=0, k=0;
    while (i<v.size()) {
        if (b+v[i]<x) {
            b+=v[i];
            if (++k==2) {
                c++, b=0, k=0;
            }
        } else if (b+v[i]==x) {
            c++, b=0, k=0;
        } else if (k>0) {
            c++, b=v[i], k=1;
        }
        i++;
    }
    if (k>0) c++;
    cout << c;
}
