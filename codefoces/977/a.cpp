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

ll gcd(ll a, ll b) {
    return b == 0 ? a: gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    for (int i=0; i<k; i++) {
        if (n % 10 == 0) n /= 10;
        else n -= 1;
    }

    cout << n;

    return 0;
}
