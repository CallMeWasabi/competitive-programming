#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// solved

bool is_safe(vector<vector<char>>& b, int _i, int _j) {
    for (int i=0; i<8; i++) {
        int row=0, col=0;
        for (int j=0; j<8; j++) {
            if (b[i][j]=='q') row++;
            if (b[j][i]=='q') col++;
        }
        if (row > 1 || col > 1) return 0;
    }

    for (int i=_i-1, j=_j-1; i>=0 && j>=0; i--, j--) if (b[i][j]=='q') return 0;
    for (int i=_i-1, j=_j+1; i>=0 && j<8; i--, j++) if (b[i][j]=='q') return 0;
    for (int i=_i+1, j=_j-1; i<8 && j>=0; i++, j--) if (b[i][j]=='q') return 0;
    for (int i=_i+1, j=_j+1; i<8 && j<8; i++, j++) if (b[i][j]=='q') return 0;

    return 1;
}

ll pat = 0;
void solve(vector<vector<char>>& b, int ind) {
    if (ind==8) {
        pat++;
        return;
    }

    for (int j=0; j<8; j++) {
        if (b[ind][j]=='*') continue;
        b[ind][j]='q';
        if (is_safe(b, ind, j)) solve(b, ind+1);
        b[ind][j]='.';
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<vector<char>> b(8, vector<char>(8));
    char c;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> c;
            b[i][j]=c;
        }
    }

    solve(b, 0);

    cout << pat;

    return 0;
}
