#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    while (getline(cin, s)) {
        int sz=s.length();
        vector<int> idx(sz);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (a==b) return false;
            int j=0;
            while (j<sz&&s[a]==s[b]) {
                a=(a+1)%sz;
                b=(b+1)%sz;
                j++;
            }
            return s[a]<s[b];
        });
        string result;
        result.reserve(sz);
        for (auto i: idx) {
            if (i-1<0) i=sz-1;
            else i=i-1;
            result+=s[i];
        }
        cout << result << '\n';
    }

    return 0;
}
