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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, k, m;
        cin >> n >> k >> m;

        if (m < k) cout << "NO\n";
        else {
            cout << "YES\n";

            ll d = floor((double)m/k);
            ll i=0;
            while (i<n) {
                ll j=0, sum=m;
                for (; j<k && i<n; j++, i++) {;
                    if (j + 1 == k && sum >= d) cout << sum << ' ';
                    else {
                        cout << d << ' ';
                        sum -= d;
                    }
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
