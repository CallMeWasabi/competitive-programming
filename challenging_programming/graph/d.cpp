#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    queue<int> q;
    vector<int> ans;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i=1; i<=n; i++) for (auto j: adj[i]) indegree[j]++;

    for (int i=1; i<=n; i++) if (indegree[i]==0) q.push(i);

    while (!q.empty()) {
        auto t=q.front();
        q.pop();
        ans.push_back(t);
        for (auto next: adj[t]) {
            indegree[next]--;
            if (indegree[next]==0) q.push(next);
        }
    }

    if (ans.size() != n) cout << "IMPOSSIBLE";
    else for (auto i: ans) cout << i << ' ';

    return 0;
}
