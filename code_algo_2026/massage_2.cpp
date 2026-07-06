    #include <functional>
    #include <ios>
    #include <iostream>
    #include <queue>
    #include <utility>
    #include <vector>
    using ll = long long;
    using namespace std;

    const int sz = 500005;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tr[sz];

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);

        int N;
        cin >> N;
        for (int i=0; i<N-1; i++) {
            int x, y;
            cin >> x >> y;
            tr[x].push({0, y});
        }

        while (1) {
            int t=1;
            while (!tr[t].empty()) {
                auto [resis, k] = tr[t].top(); tr[t].pop();
                if (tr[k].empty()) {
                    cout << k << '\n';
                    break;
                }
                else {
                    tr[t].push({resis+1, k});
                    t = k;
                }
            }
            if (tr[1].size() == 0) {
                cout << 1 << '\n';
                break;
            }
        }
    }
