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
        int n;
        cin >> n;
        vector<ll> v(n);
        int neg=0, pos=0;
        for (auto &i: v) {
            cin >> i;
            if (i > 0) pos++;
            else neg++;
        }

        bool possible = 1;

        if (n % 2 == 1) possible = 0;
        else if (pos > neg) {
            ll i = 0;
            while (i < n-1 && pos != neg) {
                if (v[i] == v[i+1] && v[i] > 0) pos -= 2, neg += 2, i=i+2;
                else i++;
            }
            if (pos != neg) possible = 0;
        } else {
            ll i = 0;
            while (i < n-1 && pos != neg) {
                if (v[i] == v[i+1] && v[i] < 0) neg -= 2, pos += 2, i = i + 2;
                else i++;
            }
            if (pos != neg) possible = 0;
        }

        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
