#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << arr[x][y] - arr[i - 1][y] - arr[x][j - 1] + arr[i - 1][j - 1] << '\n';
    }

    return 0;
}