#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    unordered_map<int,int> mp;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    int M;
    cin >> M;
    vector<int> queries(M);
    for(int i = 0; i < M; i++){
        cin >> queries[i];
    }
    for(int i = 0; i < M; i++){
        cout << mp[queries[i]] << " ";
    }
    return 0;
}