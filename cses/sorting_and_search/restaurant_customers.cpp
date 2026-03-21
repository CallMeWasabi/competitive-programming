#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    set<int> cord;
    for (auto &[f, s]: v) cin >> f >> s, cord.insert(f), cord.insert(s);

    unordered_map<int, int> m;
    int i=0;
    for (auto &j: cord) m[j]=i++;

    int sz=cord.size() + 1;
    vector<int> mark(sz, 0);
    for (auto &[f, s]: v) {
        mark[m[f]]++;
        mark[m[s]]--;
    }

    int mx=-1, k=0;
    for (int i=0; i<sz; i++) mx=max(mx, k+=mark[i]);
    cout << mx;

    return 0;
}
