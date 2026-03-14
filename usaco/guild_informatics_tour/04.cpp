#include <string>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

// unsubmit

struct memo {
    bool possible;
    ll cur_boss;
    ll cur_healt;
    ll total_dmg;
};

string to_string(memo& m) {
    return to_string(m.possible) + ' ' + to_string(m.cur_boss) + ' ' + to_string(m.cur_healt) + ' ' + to_string(m.total_dmg);
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;
    vector<pair<ll, ll>> boss(n);
    vector<tuple<ll, ll, ll>> hero(m);
    for (auto &[h, d]: boss) cin >> h >> d;
    for (auto &[h, d, c]: hero) cin >> h >> d >> c;

    vector<memo> dp(c+1);
    auto &[b_hp, b_dmg] = boss[0];
    auto &[h_hp, h_dmg, price] = hero[0];
    ll mx=0;
    dp[c]=memo{1, 0, b_hp, 0};
    if (c>=price) {
        if (b_dmg==0 || b_hp - h_dmg * (h_hp/b_dmg) <= 0) dp[c-price]=memo{1, 1, boss[1].first, b_hp};
        else dp[c-price]=memo{1, 0, b_hp - h_dmg * (h_hp/b_dmg), h_dmg * (h_hp/b_dmg)};
    }
    mx=max(dp[c].total_dmg, dp[c-price].total_dmg);

    for (int i=1; i<m; i++) {
        auto &[h_hp, h_dmg, price] = hero[i];
        if (price > c) continue;
        for (int j=price; j<=c; j++) {
            if (dp[j].possible) {
                // can hit util died ?
                int cur_boss=dp[j].cur_boss;
                int dmg=dp[j].cur_healt;
                if (boss[cur_boss].second==0 || dp[j].cur_boss - dmg <= 0) {
                    int next_boss=(dp[j].cur_boss + 1)%n;
                    dp[j-price]=memo{1, next_boss, boss[next_boss].first, dp[j].total_dmg + dmg};
                } else {
                    int cur_boss=dp[j].cur_boss;
                    int dmg=h_dmg * (h_hp/boss[cur_boss].second);
                    dp[j-price]=memo{1, dp[j].cur_boss, dp[j].cur_healt - dmg, dp[j].total_dmg + dmg};
                }
                mx=max(mx, dp[j-price].total_dmg);
            }
        }
    }

    for (int i=0; i<=c; i++) {
        cout << i << ' ' << to_string(dp[i]) << '\n';
    }

    cout << mx;

    return 0;
}
