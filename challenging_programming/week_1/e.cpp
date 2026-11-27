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
using vi = vector<int>;

vector<pii> tree[200005];
vector<bool> used(200005, false);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<vi> arr(9, vi(9, 0));
    for (int i=0; i<9; i++) for (int j=0; j<9; j++) {
        char c;
        cin >> c;
        if (c=='.') arr[i][j] = 0;
        else arr[i][j] = c - '0';
    }

    bool invalid = 0;
    for (int i=0; i<9; i++) for (int j=0; j<9; j++) {
        if (invalid) break;
        if (arr[i][j] != 0) {
            for (int k=0; k<9; k++) {
                if (k != j && arr[i][k] == arr[i][j]) {
                    invalid = 1;
                    break;
                }
            }
            for (int k=0; k<9; k++) {
                if (k != i && arr[k][j] == arr[i][j]) {
                    invalid = 1;
                    break;
                }
            }

        }
    }

    for (int i=0; i<3; i++) {
        if (invalid) break;
        for (int j=0; j<3; j++) {
            if (invalid) break;

            vector<int> dup(10, 0);
            for (int k=i*3; k<i*3+3; k++) {
                if (invalid) break;
                for (int l=j*3; l<j*3+3; l++) {
                    if (arr[k][l] != 0 && ++ dup[arr[k][l]] > 1) {
                        invalid = 1;
                        break;
                    }
                }
            }
        }
    }

    cout << arr << '\n';

    if (invalid) {
        cout << "ERROR\n";
        return 0;
    }

    return 0;

    set<int> b[9][9];
    for (int i=0; i<9; i++) for (int j=0; j<9; j++) for (int k=1; k<=9; k++) b[i][j].insert(k);

    for (int i=0; i<9; i++) for (int j=0; j<9; j++) {
        char c;
        cin >> c;
        if (c=='.') continue;

        int digit = c-'0';
        for (int k=0; k<9; k++) b[i][k].erase(digit), b[k][j].erase(digit);
        // for (int k=i/3; k<)
    }

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << "b[" << i << "][" << j << "]: " << b[i][j] << '\n';
        }
    }

    return 0;
}
