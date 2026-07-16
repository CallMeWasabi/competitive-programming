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

    int n;
    string s;
    cin >> n >> s;

    map<string, int> mp;
    for (int i=0; i<n-1; i++) {
        string k = s.substr(i, 2);
        mp[k]++;
    }

    string ans;
    int mx=0;
    for (auto &[k, v]: mp) {
        if (v>mx) {
            ans = k;
            mx = v;
        }
    }

    cout << ans;

    return 0;
}
