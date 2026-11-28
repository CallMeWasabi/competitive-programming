#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

using namespace std;
using ll = long long;

#define dbg(x) cerr << #x << ": " << x << '\n'

string bin(int i, int n) {
    string s;
    for (int j=0; j<n; j++) {
        s = to_string(((i >> j) & 1)) + s;
    }
    return s;
}

void run_case() {
    int n;
    cin >> n;
    for (int i=0; i<1<<n; i++) {
        cout << bin(i, n) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    run_case();

    return 0;
}
