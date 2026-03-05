#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> v(n);
    set<ll> memo;
    for (auto &i: v) cin >> i;
    sort(v.begin(), v.end());

    ll c=0;
    for (auto &i: v) {
        memo.insert(i);
        c+=i;
        memo.insert(c);
    }
    auto it = memo.begin();
    ll i=*it;
    it++;
    while (it!=memo.end()) {
        if (*it-i>1) {
            cout << i+1;
            break;
        }
        i=*it;
        it++;
    }

    return 0;
}
