#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int sum = i, temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}