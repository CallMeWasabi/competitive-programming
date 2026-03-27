#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1 = "monkey";
    string s2 = "money";

    s1 = " " + s1;
    s2 = " " + s2;
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));
    for (int i=0; i<s1.length(); i++) dp[i][0] = i;
    for (int i=0; i<s2.length(); i++) dp[0][i] = i;

    for (int i=1; i<s1.length(); i++) {
        for (int j=1; j<s2.length(); j++) {
            if (s1[i]==s2[j] && i > 0 && j > 0) dp[i][j] = dp[i-1][j-1];
            else {
                int a, b, c;
                a=b=c=0;
                if (i>0&&j>0) a=dp[i-1][j-1];
                if (i>0) b=dp[i-1][j];
                if (j>0) c=dp[i][j-1];

                dp[i][j] = 1 + min({a, b, c});
            }
        }
    }

    cout << "  ";
    for (auto &c: s2) cout << c << " ";
    cout << '\n';

    for (int i=0; i<s1.length(); i++) {
        cout << s1[i] << " ";
        for (int j=0; j<s2.length(); j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
