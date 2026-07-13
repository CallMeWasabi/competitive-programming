#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;

const int root_n = 512;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (auto &i: v) cin >> i;

    map<int, int> mp;
    for (int i=0, cpress=1; i<n; i++) {
        if (mp.find(v[i]) != mp.end()) v[i] = mp[v[i]];
        else mp[v[i]] = cpress++, v[i] = mp[v[i]];
    }

    vector<int> ans(q);
    vector<tuple<int, int, int>> queries(q);
    int i = 0;
    for (auto &[l, r, kth]: queries) cin >> l >> r, kth=i++, l--, r--;
    sort(queries.begin(), queries.end(), [](auto& a, auto& b) {
        auto &[i, j, _] = a;
        auto &[u, v, __] = b;
        if (i / root_n < u / root_n) return true;
        else if (i / root_n > u / root_n) return false;
        return j < v;
    });

    int freq[200005];
    memset(freq, 0, sizeof(freq));

    ll dist = 0, cur_l = get<0>(queries[0]), cur_r = get<0>(queries[0]);
    freq[v[cur_l]]++;
    dist++;

    for (auto &[l, r, kth]: queries) {
        while (cur_l > l) {
            cur_l--;
            if (++freq[v[cur_l]] == 1) dist++;
        }
        while (cur_r < r) {
            cur_r++;
            if (++freq[v[cur_r]] == 1) dist++;
        }
        while (cur_l < l) {
            if (--freq[v[cur_l]] == 0) dist--;
            cur_l++;
        }
        while (cur_r > r) {
            if (--freq[v[cur_r]] == 0) dist--;
            cur_r--;
        }

        ans[kth] = dist;
    }

    for (auto &i: ans) cout << i << '\n';

    return 0;
}
