#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        if (m > n-1) {
            ll rest = m - (n-1);

            for (int i=n, j=0; j<n-2; i--, j++) cout << i << ' ';

            if (rest % 2) cout << "1 2";
            else cout << "2 1";

        } else {
            for (int i=n, j=0; j<m; i--, j++) cout << i << ' ';
            for (int i=1, j=0; j<n-m; i++, j++) cout << i << ' ';
        }

        cout << '\n';
    }

    return 0;
}
