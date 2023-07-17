#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<vector<int>> arr(15, vector<int>(15, 0));
    for (int i = 1; i <= 14; ++i) {
        arr[0][i] = i;
        arr[i][1] = 1;
    }

    for (int i = 1; i <= 14; ++i) {
        for (int j = 2; j <= 14; ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int k, n;
        cin >> k >> n;
        cout << arr[k][n] << '\n';
    }

    return 0;
}