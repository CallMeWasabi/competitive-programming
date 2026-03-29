#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    set<int> s;
    char c;
    int i=0;
    while ((cin >> c) != '\n') {
        if (c=='1') s.insert(i);
        i++;
    }

    int k;
    while (q--) {
        cin >> c >> k;
        if (c==0) {
            if (s.count(k)==0) s.insert(k);
        }
        else if (c==1) {
            if (s.count(k)>0) s.erase(k);
        }
        else if (c==2) {
            if (s.count(k)>0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (c==3) {
            auto it = s.lower_bound(k);
            if (it==s.end()) cout << "-1\n";
            else cout << *it << '\n';
        }
        else {
            auto it = s.upper_bound(k);
            it--;
            if (it == prev(s.begin())) cout << "-1\n";
            else cout << *it << '\n';
        }
    }

    return 0;
}
