#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        if (x==y) cout << 0 << '\n';
        else if (x<y) {
            int cnt=0;
            while (x<y) {
                if (x*2<y) x*=2;
                else x=y;
                cnt++;
            }
            cout << cnt << '\n';
        }
        else if (x>y) {
            int cnt=0, prev=-1;
            bool f=0;
            while (x>y) {
                if (prev==x) {
                    f=1;
                    cout << -1 << '\n';
                    break;
                }
                ll lo=ceil(2.0*x/3+0.1);
                if (lo<y) x=y;
                else {
                    prev=x;
                    x=lo;
                }
                cnt++;
            }
            if (!f) cout << cnt << '\n';
        }
    }

    return 0;
}
