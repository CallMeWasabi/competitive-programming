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
        string s;
        cin >> n >> s;

        ll mx=0, con=0;
        for (int i=0; i<n; i++) {
            if (s[i] == '*') {
                mx = max(mx, con);
                con = 0;
            } else if (s[i] == '#') con++;
        }
        mx = max(mx, con);

        cout << (mx + 1) / 2 << '\n';
    }

    return 0;
}
