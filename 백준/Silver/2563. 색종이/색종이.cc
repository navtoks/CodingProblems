#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    vector<vector<bool>> arr(100, vector<bool>(100, false));

    int N;
    cin >> N;
    for (int n = 0; n < N; ++n) {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                arr[x + i][y + j] = true;
            }
        }
    }

    int cnt = 0;
    for (const auto& row : arr) {
        for (const auto& elt : row) {
            if (elt) ++cnt;
        }
    }
    cout << cnt;

    return 0;
}