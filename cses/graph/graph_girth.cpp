#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

const int N = 2552;
vector<int> v[N];
vector<bool> vis(N, 0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair<int, int>> q;
    int mn=1e9;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            q.push({i, 1});
            while (!q.empty()) {
                auto [at, s]=q.front(); q.pop();
                if (vis[at]) {
                    mn=min(mn, s);
                    continue;
                } else vis[at]=1;
                for (auto &to: v[at]) q.push({to, s+1});
            }
        }
    }


    if (mn==1e9) cout << "-1";
    else cout << mn;

    return 0;
}
