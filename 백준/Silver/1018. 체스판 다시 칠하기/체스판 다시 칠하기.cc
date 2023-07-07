#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Count(const vector<string>& arr, int x, int y) {
    int bw = 0;
    int wb = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2) {
                if (arr[y + i][x + j] == 'B') ++bw;
                else ++wb;
            }
            else {
                if (arr[y + i][x + j] == 'W') ++bw;
                else ++wb;
            }
        }
    }
    return min(bw, wb);
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for (auto& elt : arr) cin >> elt;

    int min_cnt = 64;
    for (int y = 0; y <= n - 8; ++y) {
        for (int x = 0; x <= m - 8; ++x) {
            int cnt = Count(arr, x, y);
            min_cnt = min(cnt, min_cnt);
        }
    }
    cout << min_cnt;

    return 0;
}