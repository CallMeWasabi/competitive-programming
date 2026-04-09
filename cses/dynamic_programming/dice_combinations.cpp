#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll m = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<ll> dp(n+1, 0);
    dp[0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<6; j++) {
            if (v[j]>i) break;
            dp[i]=((dp[i]%m)+(dp[i-v[j]]%m))%m;
        }
    }

    cout << dp[n];

    return 0;
}
