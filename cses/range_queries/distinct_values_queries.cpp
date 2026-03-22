#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n), ans(q);
    vector<tuple<int, int, int>> qr(q);
    for (auto &i: v) cin >> i;
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        auto &[f, s, t] = qr[i];
        f=a-1, s=b-1, t=i;
    }

    map<int, int> mp;
    sort(qr.begin(), qr.end());
    auto &[pl, pr, _] = qr[0];
    for (int i=pl; i<=pr; i++) mp[v[i]]++;
    ans[_]=mp.size();
    for (int i=1; i<qr.size(); i++) {
        auto &[l, r, ind] = qr[i];
        if (l<=pr) {
            for (int j=pl; j<l; j++) if (--mp[v[j]]==0) mp.erase(v[j]);

            if (r<=pr) for (int j=pr; j>r; j--) {
                if (--mp[v[j]]==0) mp.erase(v[j]);
            }
            else for (int j=pr+1; j<=r; j++) mp[v[j]]++;
        } else {
            mp.clear();
            for (int j=l; j<=r; j++) mp[v[j]]++;
        }

        pl=l, pr=r;
        ans[ind]=mp.size();
    }

    for (auto &i: ans) cout << i << '\n';



    return 0;
}
