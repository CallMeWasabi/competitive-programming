#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, y, x, k, r;
    cin >> t;
    while (t--) {
        cin >> y >> x;
        if (y >= x) {
            k = y*y;
            if (y%2) r=k-((y-1)*2)+x-1;
            else r=k-x+1;
        } else {
            k = x*x;
            if (x%2) r=k-y+1;
            else r=k-((x-1)*2)+y-1;
        }
        cout << r << '\n';
    }


    return 0;
}
