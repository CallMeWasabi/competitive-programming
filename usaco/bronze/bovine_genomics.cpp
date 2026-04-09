#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<string> spot(n), plain(n);
    for (auto &s: spot) cin >> s;
    for (auto &s: plain) cin >> s;

    array<int, 26> memo1, memo2;
    int cnt=0;
    for (int i=0; i<m; i++) {
        fill(memo1.begin(), memo1.end(), 0);
        fill(memo2.begin(), memo2.end(), 0);

        for (auto &s: spot) memo1[s[i]-'A']++;
        for (auto &s: plain) memo2[s[i]-'A']++;

        bool intersec=0;
        for (int j=0; j<26; j++) if (memo1[j]>0&&memo2[j]>0) {
            intersec=1;
            break;
        }
        if (!intersec) cnt++;
    }

    cout << cnt;


    return 0;
}
