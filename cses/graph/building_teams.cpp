#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;
using int128 = __int128;

#define dbg(x) cerr << #x << ": " << x << '\n'

const int mx = 1e5 + 5;
vector<int> g[mx];
vector<int> color(mx, -1);

void run_case() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bool flag = 1;
  vector<bool> vis(mx, 0);
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;

    vis[i] = 1;
    queue<int> q;
    q.push(i);
    if (color[i] == -1)
      color[i] = 1;
    while (!q.empty() && flag) {
      auto x = q.front();
      q.pop();
      int opp = color[x] == 1 ? 2 : 1;
      for (auto &v : g[x]) {
        if (color[v] == color[x]) {
          flag = 0;
          break;
        } else if (vis[v])
          continue;
        else if (color[v] == -1) {
          vis[v] = 1;
          color[v] = opp;
          q.push(v);
        }
      }
    }
  }
  if (flag)
    for (int i = 1; i <= n; i++)
      cout << color[i] << ' ';
  else
    cout << "IMPOSSIBLE";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int test = 1;
  while (test--)
    run_case();

  return 0;
}
