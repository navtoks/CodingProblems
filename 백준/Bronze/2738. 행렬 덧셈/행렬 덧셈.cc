#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using mi = vector<vi>;

void SetArr(mi& arr) {
    for (auto& row : arr) {
        for (auto& elt : row) cin >> elt;
    }
}

int main() {
    cin.tie(nullptr);   ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    mi a(n, vi(m)), b(n, vi(m));
    SetArr(a);
    SetArr(b);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] += b[i][j];
        }
    }

    for (const auto& row : a) {
        for (const auto& elt : row) cout << elt << ' ';
        cout << '\n';
    }

    return 0;
}