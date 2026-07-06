#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    vector<ll> v(n);
    for (auto &i: v) cin >> i;

    sort(v.begin(), v.end());

    ll t=0;
    int i=0, j=v.size()-1;


    return 0;
}
