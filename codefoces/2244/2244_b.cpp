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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (auto &i: v) cin >> i;

        bool valid = 1;
        if (n == 2 && v[0] == v[1] && v[0] == 1) valid = 0;
        else {
            for (int i=0; i<n-1; i++) {
                if (v[i] == 1 || v[i]<v[i+1]) continue;
                else if (v[i] >= v[i+1]) {
                    if (i == 0) {
                        ll diff = v[i] - 1;
                        v[i] -= diff;
                        v[i+1] += diff;
                    } else {
                        ll diff = v[i] - v[i-1] - 1;
                        v[i] = v[i-1] + 1;
                        v[i+1] += diff;
                    }
                }
            }
        }

        for (int i=0; i<n-1; i++) {
            if (v[i]>=v[i+1]) {
                valid = 0;
                break;
            }
        }

        if (valid) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
