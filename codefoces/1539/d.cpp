#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <utility>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdint>
#include <cmath>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;

const ll INF = 1e9 + 7;

struct Product {
    ll ai;
    ll bi;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Product> v(n);
    for (int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.bi != b.bi) return a.bi < b.bi ? 1: 0;
        return a.ai < b.ai ? 1: 0;
    });

    ll l=0, r=1e15;
    while (l<r) {
        ll m = (l+r)/2;
        ll cost = 0, cnt = 0;

        vector<Product> cp(v);

        int i=0, j=v.size()-1;
        while (i <= j) {
            if (cp[i].bi <= cnt) {
                cost += cp[i].ai;
                cnt += cp[i].ai;
                i++;
            } else {
                ll t = min(cp[i].bi - cnt, cp[j].ai);
                cost += 2 * t;
                cnt += t;
                cp[j].ai -= t;
                if (cp[j].ai == 0) j--;
            }
        }

        if (cost > m) l=m+1;
        else r=m;
    }

    cout << l;

    return 0;
}
