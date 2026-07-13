#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<ll> v;
    int a;
    while ((cin >> a) && a != 42) v.push_back(a);
    for (auto &i: v) cout << i << '\n';

    return 0;
}
