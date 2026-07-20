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
#include <numeric>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    for (int i=2; i<=n; i++) {
        vector<int> f;
        int k = i;
        for (int x=2; x*x<=k; x++) {
            while (k%x == 0) {
                f.push_back(x);
                k /= x;
            }
        }
        if (k > 1) f.push_back(k);

        f.erase(unique(f.begin(), f.end()), f.end());
        if (f.size() == 2) ans++;
    }

    cout << ans;


    return 0;
}
