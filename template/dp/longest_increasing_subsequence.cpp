#include <algorithm>
#include <vector>
using namespace std;

vector<int> n_sqrt(vector<int>& input) {
    vector<int> dp(input.size(), 1);

    for (int i=1; i<input.size(); i++) {
        for (int j=0; j<i; j++) {
            if (input[i] > input[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp;
}

vector<int> n_log_n(vector<int>& input) {
    vector<int> dp;
    for (int i=0; i<input.size(); i++) {
        if (input[i] > dp.back())  dp.push_back(input[i]);
        else {
            int ind = lower_bound(dp.begin(), dp.end(), input[i]) - dp.begin();
            dp[ind] = input[i];
        }
    }

    return dp;
}

int main() {
    vector<int> input = {2, 5, 1, 0, 7, 3, 4, 6, 99, 10, 8};

    return 0;
}
