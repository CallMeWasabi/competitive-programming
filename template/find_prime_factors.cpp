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

vector<ll> factors(ll n) {
    vector<ll> f;
    for (int x=2; x*x<=n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);

    return f;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);


    return 0;
}
