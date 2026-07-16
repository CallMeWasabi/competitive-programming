#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n*2);
        for (auto &i: v) cin >> i;

        for (int i=0; i<n*2; i += 2) cout << v[i+1] << ' ' << v[i] << ' ';
        cout << '\n';
    }

    return 0;
}
