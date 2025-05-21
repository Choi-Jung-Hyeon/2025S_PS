#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int left = x;
    int right = w-x;
    int up = h-y;
    int down = y;

    cout << min({left, right, up, down});
    return 0;
}