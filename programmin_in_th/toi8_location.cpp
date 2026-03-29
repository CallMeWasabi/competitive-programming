#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> v(m, vector<int>(n, 0));
    vector<vector<int>> pf(m, vector<int>(n, 0));
    for (auto &i: v) for (auto &j: i) cin >> j;

    for (int i=0; i<m; i++) {
        pf[i][0]=v[i][0];
        for (int j=1; j<n; j++) pf[i][j]=pf[i][j-1]+v[i][j];
    }

    for (int i=0; i<n; i++) for (int j=1; j<m; j++) pf[j][i]+=pf[j-1][i];

    ll MX = -1;
    for (int right=k-1; right<n; right++) {
        for (int down=k-1; down<m; down++) {
            ll s = pf[down][right];

            if (right - k >= 0) s -= pf[down][right-k];
            if (down - k >= 0) s -= pf[down-k][right];
            if (right - k >= 0 && down - k >= 0) s += pf[down-k][right-k];

            MX=max(MX, s);
        }
    }

    cout << MX;

    return 0;
}
