#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;
using int128 = __int128;

#define dbg(x) cerr << #x << ": " << x << '\n'

const int mx = 1001;
char b[mx][mx];
char path[mx][mx];
bool vis[mx][mx];
int n, m;

void backtrack(int x, int y) {
  vector<char> p;
  while (b[y][x] != 'A') {
    char d = path[y][x];
    p.push_back(d);
    if (d == 'U')
      y++;
    else if (d == 'D')
      y--;
    else if (d == 'R')
      x--;
    else
      x++;
  }
  reverse(p.begin(), p.end());
  cout << "YES\n";
  cout << p.size() << '\n';
  for (auto c : p)
    cout << c;
}

bool valid(int x, int y) {
  if (x < 0 || x >= m || y < 0 || y >= n || vis[y][x] || b[y][x] == '#')
    return false;
  return true;
}

void run_case() {
  cin >> n >> m;

  int ax, ay;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
      if (b[i][j] == 'A')
        ax = j, ay = i;
    }

  bool flag = 0;
  queue<pair<int, int>> q;
  vis[ay][ax] = 1;
  q.push({ax, ay});
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (b[y][x] == 'B') {
      flag = 1;
      backtrack(x, y);
      break;
    }

    if (valid(x + 1, y)) {
      vis[y][x + 1] = 1;
      path[y][x + 1] = 'R';
      q.push({x + 1, y});
    }
    if (valid(x - 1, y)) {
      vis[y][x - 1] = 1;
      path[y][x - 1] = 'L';
      q.push({x - 1, y});
    }
    if (valid(x, y + 1)) {
      vis[y + 1][x] = 1;
      path[y + 1][x] = 'D';
      q.push({x, y + 1});
    }
    if (valid(x, y - 1)) {
      vis[y - 1][x] = 1;
      path[y - 1][x] = 'U';
      q.push({x, y - 1});
    }
  }
  if (!flag)
    cout << "NO";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int test = 1;
  while (test--)
    run_case();

  return 0;
}
