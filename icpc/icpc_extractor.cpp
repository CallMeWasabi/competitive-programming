#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int l=0, r=s.size()/4;
        while (l < r) {
            vector<bool> used(s.size(), 1);
            int m = (l+r)/2;
            int ic=0, pc=0;

            int p_pos=0;
            char chars='i';
            for (int i=0; i<s.size(); i++) {
                if (s[i]==chars && chars=='i') {
                    p_pos=i;
                    chars='p';
                } else if (s[i]==chars && chars=='p') {
                    used[p_pos]=used[i]=0;
                    chars='i';
                    ic++;
                }
            }

            p_pos=0;
            chars='c';

            // todo
        }
    }

    return 0;
}
