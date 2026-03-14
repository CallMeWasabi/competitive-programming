#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i: v) cin >> i;

    int l=0;
    bool dup=0;
    map<int, int> memo;
    for (int i=0, j=n-1; i<n/2; i++, j--) {
        if (v[i]!=v[j]) l++;
        if (++memo[v[i]]>1) dup=1;
        if (++memo[v[j]]>1) dup=1;
    }

    while (q--) {
        int qi;
        cin >> qi;
        if (qi<l) cout << "NO\n";
        else if (dup || (qi-l)%2==0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
