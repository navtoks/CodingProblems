#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    mi a(n, vi(n)), b(n, vi(n));
    for (auto& row : a) for (auto& elt : row) cin >> elt;
    for (auto& row : b) for (auto& elt : row) cin >> elt;

    mi c(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][0] & b[0][j];
            for (int k = 1; k < n; ++k) {
                c[i][j] = c[i][j] | (a[i][k] & b[k][j]);
            }
        }
    }

    int cnt = 0;
    for (const auto& row : c) {
        for (const auto& elt : row) {
            if (elt) ++cnt;
        }
    }
    cout << cnt;

    return 0;
}