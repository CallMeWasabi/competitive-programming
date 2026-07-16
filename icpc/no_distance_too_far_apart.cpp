#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, a, b;
    cin >> n >> a >> b;

    ll pos_a = a+1;
    ll pos_b = n-b;
    cout << abs(pos_a - pos_b) - 1;

    return 0;
}
