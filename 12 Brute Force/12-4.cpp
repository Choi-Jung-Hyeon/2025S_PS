#include <bits/stdc++.h>
using namespace std;

int calc(vector<string>& b, int r, int c, char fc) {
    int cnt = 0;
    char ec;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                ec = fc;
            }
            else if (fc == 'B') {
                ec = 'W';
            }
            else{
                ec = 'B';
            }
            if (b[r + i][c + j] != ec) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int mn = INT_MAX;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            mn = min(mn, calc(b, i, j, 'B'));
            mn = min(mn, calc(b, i, j, 'W'));
        }
    }

    cout << mn << endl;
    return 0;
}