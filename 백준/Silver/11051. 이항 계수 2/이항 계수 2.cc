#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<vector<int>> arr(1001, vector<int>(1001, 1));
    for (int i = 2; i <= 1000; ++i) {
        arr[i][1] = i;
        for (int j = 2; j < i; ++j) {
            arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
        }
    }

    int n, k;
    cin >> n >> k;
    cout << arr[n][k];

    return 0;
}