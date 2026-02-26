#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <numeric>
using namespace std;

bool out_bound(int n, int m, int i, int j) {
    return i<0||i>=n||j<0||j>=m;
}

void solve(int n, int m) {
    const vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    const int inf=1e9+7;

    vector<vector<pair<int, int>>> r(n, vector<pair<int, int>>(m));
    for (int o=0, j=0; j<n; j++) for (int k=0; k<m; k++, o++) {
        char c;
        cin >> c;
        r[j][k]={c-'0', o};
    }

    // make adjacent list
    vector<vector<pair<int, int>>> v(n*m+1);
    for (int i=0, o=0; i<n; i++) for (int j=0; j<m; j++, o++) for (auto &[di, dj]: dir) {
        int ti=i+di, tj=j+dj;
        if (out_bound(n, m, ti, tj)) continue;
        v[o].push_back(r[ti][tj]);
    }

    int mn=inf, ind=-1;
    vector<int> ans_par;
    for (int i=0; i<m; i++) {
        vector<int> dist(n*m+1, inf);
        vector<int> par(n*m+1);
        priority_queue<pair<int, int>> pq;

        iota(par.begin(), par.end(), 0);
        pq.push({-0, i});
        dist[i]=0;
        while (!pq.empty()) {
            auto [d, at]=pq.top(); pq.pop();
            if (-d>dist[at]) continue;
            for (auto &[w, to]: v[at]) {
                if (-d+w<dist[to]) {
                    par[to]=at;
                    dist[to]=-d+w;
                    pq.push({-dist[to], to});
                }
            }
        }

        int lmn=inf, lind=-1;
        for (int j=(n-1)*m; j<n*m; j++) {
            int d=dist[j]+r[0][i].first;
            if (d<lmn) {
                lmn=d;
                lind=j;
            }
        }
        if (lmn<mn) {
            mn=lmn;
            ind=lind;
            ans_par.swap(par);
        }
    }

    unordered_set<int> path;
    int i=ind;
    while (ans_par[i]!=i) {
        path.insert(i);
        i=ans_par[i];
    }
    path.insert(i);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (path.count(i*m+j)) cout << ' ';
            else cout << r[i][j].first;
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (1) {
        int n, m;
        cin >> n >> m;
        if (n==m&&n==0) break;
        solve(n, m);
    }
}
