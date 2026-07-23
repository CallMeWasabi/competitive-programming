#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

template <typename T> T t_min(T a, T b) { return a < b ? a: b; }
template <typename T> T t_max(T a, T b) { return a > b ? a: b; }

bool solve(const vector<ll>& arr) {
    stack<pair<ll, ll>> st;
    ll s = 0;

    for (int i=0; i<arr.size(); i++) {
        ll cur_min = s;
        while (!st.empty() && st.top().first <= arr[i]) {
            cur_min = t_min(cur_min, st.top().second);
            st.pop();
        }
        if (s > cur_min) return false;
        st.push({arr[i], cur_min});
        s += arr[i];
    }

    return true;
}

void testcase() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (auto &i: arr) cin >> i;

    vector<ll> rev_arr = arr;
    for (int i=0, j=n-1; i<n/2; i++, j--) {
        ll tmp = rev_arr[i];
        rev_arr[i] = rev_arr[j];
        rev_arr[j] = tmp;
    }

    bool ans = solve(arr) & solve(rev_arr);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) testcase();

    return 0;
}
