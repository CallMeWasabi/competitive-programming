#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> input = {5, 6, 4, 2, 3}; // p * q , q * r , r * s => p, q, r, sr

    int n = input.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len=2; len<input.size(); len++) {
        for (int i=0; i<input.size() - len; i++) {
            int j=i+len;
            dp[i][j] = INT32_MAX;
            for (int k=i+1; k<j; k++) {
                dp[i][j] = min(
                    dp[i][j],
                    dp[i][k] + dp[k][j] + input[i] * input[k] * input[j]
                );
            }
        }
    }

    for (int i=0; i<input.size(); i++) {
        for (int j=0; j<input.size(); j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
