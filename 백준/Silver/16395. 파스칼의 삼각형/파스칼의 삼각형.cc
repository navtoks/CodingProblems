#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    vector<vector<ll>> arr(30, vector<ll>(30, 0));
    for (int i = 0; i < 30; ++i) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }

    for (int i = 2; i < 30; ++i) {
        for (int j = 1; j < i; ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    cout << arr[n - 1][k - 1];

    return 0;
}