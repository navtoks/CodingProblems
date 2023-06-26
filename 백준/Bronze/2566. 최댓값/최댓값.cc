#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    mi arr(9, vi(9));
    for (auto& row : arr) {
        for (auto& elt : row) cin >> elt;
    }

    vi max_js(9, 0);
    for (int i = 0; i < 9; ++i) {
        const auto& now = arr[i];
        for (int j = 0; j < 9; ++j) {
            if (now[j] > now[max_js[i]]) max_js[i] = j;
        }
    }

    int max_i = 0;
    for (int i = 0; i < 9; ++i) {
        if (arr[i][max_js[i]] > arr[max_i][max_js[max_i]]) max_i = i;
    }

    int max_j = max_js[max_i];
    cout << arr[max_i][max_j] << '\n' << max_i + 1 << ' ' << max_j + 1;

    return 0;
}