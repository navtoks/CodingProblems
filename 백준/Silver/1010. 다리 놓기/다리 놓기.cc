#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<vector<int>> arr(31, vector<int>(31));
    for (int i = 1; i <= 30; ++i) {
        arr[i][i] = 1;
        arr[1][i] = i;
    }

    for (int i = 2; i <= 30; ++i) {
        for (int j = i + 1; j <= 30; ++j) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
        }
    }
    

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, m;
        cin >> n >> m;
        cout << arr[n][m] << '\n';
    }

    return 0;
}