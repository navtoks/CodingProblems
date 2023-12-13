#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(5));
    for (auto& row : arr) {
        for (auto& elt : row) cin >> elt;
    }

    int max_i = 0, max_j = 0, max_cnt = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            int cnt = 0;
            for (const auto& elt : arr) {
                if (elt[i] && elt[j]) ++cnt;
            }
            if (cnt > max_cnt) {
                max_cnt = cnt;
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << max_cnt << '\n';
    if (!max_cnt) {
        max_i = 0;
        max_j = 1;
    }
    for (int i = 0; i < 5; ++i) {
            cout << (i == max_i || i == max_j) << ' ';
    }

    return 0;
}