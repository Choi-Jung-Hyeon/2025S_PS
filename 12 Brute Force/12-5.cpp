#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num = 666, count = 0;
    cin >> n;
    while (count < n) {
        if (to_string(num).find("666") != string::npos) {
            count++;
        }
        num++;
    }
    cout << num - 1 << endl;
    return 0;
}