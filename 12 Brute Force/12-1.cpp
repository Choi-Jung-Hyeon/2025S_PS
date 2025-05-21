#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int maxSum = 0;
    sort(cards.begin(), cards.end());
    for (int i = 0; i < n - 2; i++) {
        if (cards[i] >= m){
            break;
        }
        for (int j = i + 1; j < n - 1; j++) {
            if (cards[i] + cards[j] >= m){
                break;
            }
            for (int k = j + 1; k < n; k++) {
                int currentSum = cards[i] + cards[j] + cards[k];
                if (currentSum > m){
                    break;
                }
                maxSum = max(maxSum, currentSum);
            }
        }
    }

    cout << maxSum << endl;
    return 0;
}