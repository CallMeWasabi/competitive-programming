#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int MN=INT32_MAX;
int s=1, b=0, c=0;

void solve(vector<pair<int, int>>& v, int i) {
    if (i==v.size()) {
        if (c>0) MN = min(MN, abs(s-b));
        return;
    }

    solve(v, i+1); // ไม่เลือก

    s*=v[i].first; // เปรี้ยว
    b+=v[i].second; // ขม
    c++; // จำนวนที่เลือก
    solve(v, i+1); // เลือก
    c--;
    b-=v[i].second;
    s/=v[i].first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++) cin >> v[i].first >> v[i].second;

    solve(v, 0);

    cout << MN;

    return 0;
}
