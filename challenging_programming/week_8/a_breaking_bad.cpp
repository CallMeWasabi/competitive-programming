#include <ios>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<string, int> color;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        color[s]=0;
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        string a, b;
        cin >> a >> b;
        if (color[a]==color[b]&&color[a]==0) color[a]=1, color[b]=2;
        else if (color[a]==0) color[a]=(color[b]==1?2:1);
        else if (color[b]==0) color[b]=(color[a]==1?2:1);
        else {
            cout << "impossible";
            return 0;
        }
    }
    for (auto &[k, v]: color) if (v==1||v==0) cout << k << ' ';
    cout << '\n';
    for (auto &[k, v]: color) if (v==2) cout << k << ' ';
}
