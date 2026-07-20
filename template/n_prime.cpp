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
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    const int lim = 1e7 + 5;
    vector<bool> sieve(lim, true);
    for (int i=2; i<lim; i++) {
        if (!sieve[i]) continue;
        for (int j=2*i; j<lim; j+=i) sieve[j] = false;
    }

    int cnt;
    cin >> cnt;
    int i = 2;
    while (cnt > 0) {
        if (sieve[i]) {
            cnt--;
            if (cnt == 0) break;
        }
        i++;
    }

    cout << i;

    return 0;
}
