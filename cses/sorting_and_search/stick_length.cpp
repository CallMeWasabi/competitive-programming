#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    sort(v.begin(), v.end());

    int cost=0;
    for (int i=0; i<v.size(); i++) {
    }

    cout << cost;

    return 0;
}
