#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    ll inf = 1LL<<60;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, inf));
    for (int i=1; i<=n; i++) dist[i][i]=0;
    for (int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (c < dist[a][b]) dist[a][b] = dist[b][a] = c;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k] != inf && dist[k][j] != inf) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;
        if (dist[a][b]==inf) cout << -1 << '\n';
        else cout << dist[a][b] << '\n';
    }

    return 0;
}
