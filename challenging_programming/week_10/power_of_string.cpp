#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    while (cin >> s && s != ".") {
        int n = s.length();
        vector<int> pre(n);

        for (int i=1; i<n; i++) {
            int j=pre[i-1];
            while (j>0 && s[i]!=s[j]) j=pre[j-1];
            if (s[i]==s[j]) j++;
            pre[i]=j;
        }

        int longest_suffix=pre[n-1];
        int len=n-longest_suffix;
        if (n%len==0) cout << n/len << '\n';
        else cout << 1 << '\n';
    }

    return 0;
}
