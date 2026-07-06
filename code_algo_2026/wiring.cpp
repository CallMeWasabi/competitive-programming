#include <ios>
#include <iostream>
using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, m, x;
    cin >> n >> m >> x;
    cout << (n * m - 1) * x;

    return 0;
}
