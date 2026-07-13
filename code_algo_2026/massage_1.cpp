#include <ios>
#include <iostream>
#include <iomanip>
#include <queue>
#include <cstring>
#include <vector>
using ll = long long;
using namespace std;

vector<int> tr[1001];
double prob[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    memset(prob, 0, sizeof(prob));

    int N, q;
    cin >> N >> q;
    N = N-1;
    while (N--) {
        int x, y;
        cin >> x >> y;
        tr[x].push_back(y);
    }

    queue<int> qu;
    qu.push(1);
    prob[1] = 100;

    while (!qu.empty()) {
        int t = qu.front(); qu.pop();
        for (auto& k: tr[t]) {
            prob[k] = prob[t] / tr[t].size();
            qu.push(k);
        }
    }

    cout << setprecision(6) << fixed << prob[q];
}
