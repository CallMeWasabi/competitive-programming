#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> input = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> dp(input.size());
    dp[0]=input[0];
    int mx=dp[0];
    for (int i=1; i<input.size(); i++) {
        dp[i] = max(dp[i-1] + input[i], input[i]);
        mx = max(mx, dp[i]);
    }

    cout << mx;
}
