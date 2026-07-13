#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> arr = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };

    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> pref(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            pref[i][j] = arr[i][j];
            if (j-1 >= 0) pref[i][j] = pref[i][j-1] + arr[i][j];
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (j-1 >= 0) pref[j][i] = pref[j-1][i] + arr[j][i];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << pref[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
