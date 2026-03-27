#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> s = {3, 34, 4, 12, 5 ,2};
    int sum = 11; // can make sum from s ?

    // make matrix size s.size() * target
    vector<vector<bool>> dp(s.size(), vector<bool>(sum+1, false));
    for (int i=0; i<s.size(); i++) dp[i][0] = 1;

    for (int i=0; i<s.size(); i++) {
        for (int j=1; j<=sum; j++) {
            if (i==0) dp[i][j] = (s[i]==j);
            else {
                bool exclude = dp[i-1][j]; // if dp[i-1][j] can make then dp[i][j] can make too (inherite)
                bool include = false;
                if (j >= s[i]) include = dp[i-1][j-s[i]];

                dp[i][j] = exclude || include;
            }
        }
    }

    for (int i=0; i<s.size(); i++) {
        for (int j=0; j<=sum; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
