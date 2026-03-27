#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // size of array
    cin >> n;

    vector<int> v(n);
    for (auto &i: v) cin >> i;

    vector<int> dp(n, 0); // dp[i] = max sum from 0 .. i
    int mx;

    mx=dp[0]=v[0]; // base case

    // fill dp array
    for (int i=1; i<n; i++) {
        dp[i] = max(dp[i-1]+v[i], v[i]);
        mx = max(mx, dp[i]);
    }

    cout << "dp: ";
    for (auto &i: dp) cout << i << ' ';
    cout << "\nmax sum is: " << mx;

    return 0;
}
