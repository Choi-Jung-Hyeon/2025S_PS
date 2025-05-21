#include <bits/stdc++.h>
using namespace std;

int main() {
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    bool flag = true;
    for (int n = n0; n <= 100; n++) {
        if (a1 * n + a0 > c * n) {
            flag = false;
            break;
        }
    }

    cout << (flag ? 1 : 0) << endl;
    return 0;
}