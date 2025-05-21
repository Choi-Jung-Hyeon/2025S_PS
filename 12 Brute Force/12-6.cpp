#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int minBag = -1;
    for (int five = 0; five <= n / 5; five++) {
        for (int three = 0; three <= n / 3; three++) {
            if (5 * five + 3 * three == n) {
                int total = five + three;
                if (minBag == -1 || total < minBag) {
                    minBag = total;
                }
            }
        }
    }

    cout << minBag << endl;
    return 0;
}